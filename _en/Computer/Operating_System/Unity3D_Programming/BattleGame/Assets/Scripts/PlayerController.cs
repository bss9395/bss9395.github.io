using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using Google.Protobuf;
using Pb;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    public Animator _animator = null;
    public CharacterController _controller = null;
    public Text _playerName = null;
    public Slider _playerBlood = null;
    public GameObject _bullet = null;
    public int _playerID = 0;
    Vector3 _destination;
    State _state = State.None;

    public void Init()
    {
        try
        {
            _animator = this.GetComponent<Animator>();
            _controller = this.GetComponent<CharacterController>();
            _playerName = Instantiate(Resources.Load<GameObject>("Name")).GetComponent<Text>();
            _playerBlood = Instantiate(Resources.Load<GameObject>("Blood")).GetComponent<Slider>();
            _bullet = Resources.Load<GameObject>("Bullet");

            GameObject canvas = GameObject.Find("Canvas");
            _playerName.transform.SetParent(canvas.transform);
            _playerBlood.transform.SetParent(canvas.transform);

            _state = State.Init;
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }

    public void OnLogon(Pb.BroadCast broadcast)
    {
        if (_state == State.None)
        {
            Init();
        }

        _playerID = broadcast.Pid;
        _playerName.text = broadcast.Username;
        _playerBlood.value = broadcast.P.BloodValue;
        this.transform.position = new Vector3(broadcast.P.X, broadcast.P.Y, broadcast.P.Z);

        GameConfig._players.Add(_playerID, this);
        _state = State.Logon;
    }

    public void OnLogon(Pb.Player player)
    {
        if (_state == State.None)
        {
            Init();
        }

        _playerID = player.Pid;
        _playerName.text = player.Username;
        _playerBlood.value = player.P.BloodValue;
        this.transform.position = new Vector3(player.P.X, player.P.Y, player.P.Z);

        GameConfig._players.Add(_playerID, this);
        _state = State.Logon;
    }

    public void OnLogoff(Pb.SyncPid syncpid)
    {
        OnDestroy();
        GameConfig._players.Remove(_playerID);

        _state = State.Logoff;
    }

    public void OnDestroy()
    {
        Destroy(_playerName);
        Destroy(_playerBlood);
        Destroy(this.gameObject);
        GameConfig._players.Remove(_playerID);

        _state = State.Dead;
    }

    public void OnUpdate(Pb.BroadCast broadcast)
    {
        _destination = new Vector3(broadcast.P.X, broadcast.P.Y, broadcast.P.Z);
        _playerBlood.value = broadcast.P.BloodValue * 1.0f / 1000.0f;
        this.transform.localEulerAngles = new Vector3(this.transform.localEulerAngles.x, broadcast.P.V, this.transform.localEulerAngles.z);

        _state = State.Update;
    }

    void Update()
    {
        if (_state == State.None)
        {
            Init();
        }
        else
        {
            Move();
            Info();
        }
    }

    void Move()
    {
        Vector3 movement = _destination - this.transform.position;
        if (Vector3.Magnitude(movement) < 0.1f)
        {
            this.transform.position = _destination;

            _animator.SetFloat("Direction", 0.0f);
            _animator.SetFloat("Speed", 0.0f);

            _state = State.Rest;
        }
        else
        {
            _controller.SimpleMove(movement);

            float direction = Vector3.Dot(movement.normalized, this.transform.right);
            float speed = Vector3.Dot(movement.normalized, this.transform.forward);
            if (speed > 0.0f || direction == 1.0f || direction == -1.0f)
            {
                speed = 1.0f;
            }
            else if (speed < 0.0f)
            {
                speed = -1.0f;
            }

            //if (Mathf.Abs(speed) <= 0.1f && Mathf.Abs(direction) >= 0.9f)
            //{
            //    speed = 1f;
            //}
            //if (speed < 0 && speed > -0.8f && direction > 0.2f)
            //{
            //    speed = -1f;
            //    direction = 1f;
            //}
            //if (speed < 0 && speed > -0.8f && direction < -0.2f)
            //{
            //    speed = -1f;
            //    direction = -1f;
            //}

            _animator.SetFloat("Direction", direction);
            _animator.SetFloat("Speed", speed);

            _state = State.Move;
        }
    }

    void Info()
    {
        Vector3 playerNamePos = Camera.main.WorldToScreenPoint(this.transform.position + this.transform.up * GameConfig._heroNameAdjust);
        Vector3 bloodValuePos = Camera.main.WorldToScreenPoint(this.transform.position + this.transform.up * GameConfig._bloodValueAdjust);
        _playerName.transform.position = playerNamePos;
        _playerBlood.transform.position = bloodValuePos;
    }

    public void OnTrigger(Pb.SkillTrigger trigger)
    {
        _animator.SetTrigger("Attack");
        Vector3 position = this.transform.position + this.transform.up * GameConfig._bulletAdjust + this.transform.forward * GameConfig._bulletOffset;
        Vector3 velocity = this.transform.forward * GameConfig._bulletSpeed;

        BulletController bullet = Instantiate(_bullet, position, Quaternion.AngleAxis(90.0f, this.transform.right)).GetComponent<BulletController>();
        bullet._playerID = _playerID;
        bullet._bulletID = trigger.BulletId;
        bullet._skillID = trigger.SkillId;
        bullet._origin = position;
        bullet._velocity = velocity;
    }

    public void OnHurt(Pb.SkillContact skill)
    {
        _playerBlood.value = skill.ContactPos.BloodValue * 1.0f / 1000.0f;
    }
}
