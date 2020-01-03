using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using Google.Protobuf;
using Pb;
using UnityEngine.UI;

public class HeroController : MonoBehaviour
{
    public Animator _animator = null;
    public CharacterController _controller = null;
    public Text _heroName = null;
    public Slider _heroBlood = null;
    public GameObject _bullet = null;
    public int _heroID = 0;
    public State _state = State.None;

    public void Init()
    {
        try
        {
            _animator = this.GetComponent<Animator>();
            _controller = this.GetComponent<CharacterController>();
            _heroName = GameObject.Instantiate(Resources.Load<GameObject>("Name")).GetComponent<Text>();
            _heroBlood = GameObject.Instantiate(Resources.Load<GameObject>("Blood")).GetComponent<Slider>();
            _bullet = Resources.Load<GameObject>("Bullet");

            GameObject canvas = GameObject.Find("Canvas");
            _heroName.transform.SetParent(canvas.transform);
            _heroBlood.transform.SetParent(canvas.transform);

            _state = State.Init;
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }

    public void OnLogon(Pb.SyncPid syncpid)
    {
        if (_state == State.None)
        {
            Init();
        }

        _heroID = syncpid.Pid;
        _heroName.text = syncpid.Username;

        GameConfig._heros[_heroID] = this;
        _state = State.Logon;
    }

    public void OnLogon(Pb.BroadCast broadcast)
    {
        if (_state == State.None)
        {
            Init();
        }

        // Debug.LogError("_heroID = " + broadcast.Pid + ", _heroName = " + broadcast.Username);

        _heroID = broadcast.Pid;
        _heroName.text = broadcast.Username;
        _heroBlood.value = broadcast.P.BloodValue * 1.0f / 1000.0f;
        this.transform.position = new Vector3(broadcast.P.X, broadcast.P.Y, broadcast.P.Z);
        Info();

        GameConfig._heros[_heroID] = this;
        _state = State.Logon;
    }

    public void OnDestroy()
    {
        Destroy(_heroName);
        Destroy(_heroBlood);
        Destroy(this.gameObject);
        GameConfig._heros.Remove(_heroID);

        _state = State.Dead;
    }

    public void Update()
    {
        if (_state == State.None)
        {
            Init();
        }
        else
        {
            Move();
            Info();
            Attack();
        }

        if (_state == State.Move || _state == State.Attack)
        {
            post();
        }
    }

    public void Move()
    {
        float vertical = Input.GetAxis("Vertical");
        float horizontal = Input.GetAxis("Horizontal");
        if (vertical == 0.0f && horizontal == 0.0f)
        {
            _animator.SetFloat("Direction", 0.0f);
            _animator.SetFloat("Speed", 0.0f);
            _state = State.Rest;
        }
        else
        {
            Vector3 foreback = vertical * this.transform.forward * GameConfig._roleSpeed;
            Vector3 leftright = horizontal * this.transform.right * GameConfig._roleSpeed;
            Vector3 movement = foreback + leftright;
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
            _animator.SetFloat("Direction", direction);
            _animator.SetFloat("Speed", speed);

            _state = State.Move;
        }
    }

    public void Info()
    {
        Vector3 heroNamePos = Camera.main.WorldToScreenPoint(this.transform.position + this.transform.up * GameConfig._heroNameAdjust);
        Vector3 bloodValuePos = Camera.main.WorldToScreenPoint(this.transform.position + this.transform.up * GameConfig._bloodValueAdjust);
        _heroName.transform.position = heroNamePos;
        _heroBlood.transform.position = bloodValuePos;
    }

    float atackDeltatime = 0.0f;
    float attackInterval = 1.0f;
    public void Attack()
    {
        atackDeltatime += Time.deltaTime;
        if (atackDeltatime > attackInterval)
        {
            if (Input.GetButton("Fire1"))
            {
                _animator.SetTrigger("Attack");
                Vector3 position = this.transform.position + this.transform.up * GameConfig._bulletAdjust + this.transform.forward * GameConfig._bulletOffset;
                Vector3 velocity = this.transform.forward * GameConfig._bulletSpeed;

                BulletController bullet = Instantiate(_bullet, position, Quaternion.AngleAxis(90.0f, this.transform.right)).GetComponent<BulletController>();
                bullet._playerID = _heroID;
                bullet._skillID = 1;
                bullet._origin = position;
                bullet._velocity = velocity;

                Pb.SkillTrigger trigger = new SkillTrigger();
                trigger.Pid = _heroID;
                trigger.BulletId = bullet._bulletID;
                trigger.SkillId = 1;
                trigger.P = new Pb.Position();
                trigger.P.X = position.x;
                trigger.P.Y = position.y;
                trigger.P.Z = position.z;
                trigger.V = new Pb.Velocity();
                trigger.V.X = velocity.x;
                trigger.V.Y = velocity.y;
                trigger.V.Z = velocity.z;

                byte[] message = trigger.ToByteArray();
                NetworkHandler.Instance.SendMessage(Protocol.GAME_MSG_SKILL_TRIGGER, message);

                atackDeltatime = 0.0f;
                _state = State.Attack;
            }
        }
    }

    public void post()
    {
        Pb.Position position = new Pb.Position();
        position.X = this.transform.position.x;
        position.Y = this.transform.position.y;
        position.Z = this.transform.position.z;
        position.V = this.transform.localEulerAngles.y;
        position.BloodValue = (int)(_heroBlood.value * 1000.0f);

        byte[] message = position.ToByteArray();
        NetworkHandler.Instance.SendMessage(Protocol.GAME_MSG_NEW_POSTION, message);
    }

    public void OnHurt(Pb.SkillContact skill)
    {
        _heroBlood.value = skill.ContactPos.BloodValue * 1.0f / 1000.0f;
    }
}
