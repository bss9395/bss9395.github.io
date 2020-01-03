using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;
using Google.Protobuf;
using Pb;

public class ChatController : MonoBehaviour
{
    public Text _chatText = null;
    public InputField _inputField = null;
    public Queue<string> _messageQueue = new Queue<string>();

    public void OnChat(Pb.BroadCast broadcast)
    {
        string content = string.Format("{0}: {1}\n", broadcast.Username, broadcast.Content);
        _messageQueue.Enqueue(content);
        while (_messageQueue.Count > GameConfig._chatLinesMax)
        {
            _messageQueue.Dequeue();
        }

        string display = "";
        foreach (var message in _messageQueue)
        {
            display += message;
        }
        _chatText.text = display;
    }

    void Start()
    {
        try
        {
            _chatText = GameObject.Find("ChatText").GetComponent<Text>();
            _inputField = GameObject.Find("InputField").GetComponent<InputField>();
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }


    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            Pb.Talk talk = new Pb.Talk();
            talk.Content = _inputField.text;
            byte[] message = talk.ToByteArray();
            NetworkHandler.Instance.SendMessage(Protocol.GAME_MSG_TALK_CONTENT, message);

            _inputField.text = "";
        }
    }
}
