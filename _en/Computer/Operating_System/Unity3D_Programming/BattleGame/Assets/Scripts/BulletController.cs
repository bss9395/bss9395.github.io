using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Google.Protobuf;
using Pb;

public class BulletController : MonoBehaviour
{
    public int _bulletID = 0;
    public int _playerID = 0;
    public int _skillID = 0;
    public Vector3 _origin;
    public Vector3 _velocity;
    public float _fadeAway = 100.0f;

    void Start()
    {
        GameConfig._bulletID += 1;
        _bulletID = GameConfig._bulletID;
        this.GetComponent<Rigidbody>().velocity = _velocity;
    }

    void Update()
    {
        if (Vector3.Distance(_origin, this.transform.position) > _fadeAway)
        {
            Destroy(this.gameObject);
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if ("Hero".Equals(collision.collider.tag))
        {
            HeroController hero = collision.collider.GetComponent<HeroController>();
            if (_playerID == hero._heroID)
            {
                Debug.Log("子弹打到自己了。。。");
            }
        }
        if ("Player".Equals(collision.collider.tag))
        {
            PlayerController player = collision.collider.GetComponent<PlayerController>();
            if (_playerID != player._playerID)
            {
                Pb.Position position = new Pb.Position();
                position.X = collision.contacts[0].point.x;
                position.Y = collision.contacts[0].point.y;
                position.Z = collision.contacts[0].point.z;

                Pb.SkillContact crash = new Pb.SkillContact();
                crash.BulletId = _bulletID;
                crash.SkillId = _skillID;
                crash.SrcPid = _playerID;
                crash.TargetPid = player._playerID;
                crash.ContactPos = position;

                byte[] message = crash.ToByteArray();
                NetworkHandler.Instance.SendMessage(Protocol.GAME_MSG_SKILL_CONTACT, message);
            }
        }

        Destroy(this.gameObject);
    }
}
