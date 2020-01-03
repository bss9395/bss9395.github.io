using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Google.Protobuf;
using Pb;

public class DoorController : MonoBehaviour
{
    void Update()
    {
        this.transform.Rotate(0.0f, GameConfig._rotateSpeed * Time.deltaTime, 0.0f);
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Hero")
        {
            HeroController hero = collision.collider.GetComponent<HeroController>();
            Pb.ChangeWorldRequest request = new Pb.ChangeWorldRequest();
            request.Pid = hero._heroID;
            request.SrcId = GameConfig._desertSceneID;
            request.TargetId = GameConfig._roomSceneID;

            byte[] message = request.ToByteArray();
            NetworkHandler.Instance.SendMessage(Protocol.GAME_MSG_CHANGE_WORLD, message);
        }
    }
}
