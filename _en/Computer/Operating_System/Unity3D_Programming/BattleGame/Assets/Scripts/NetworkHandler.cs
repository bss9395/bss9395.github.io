using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using Google.Protobuf;
using Pb;

public class Message
{
    public int _messageID;
    public byte[] _messageBody;
    public Message(int messageID, byte[] messageBody)
    {
        _messageID = messageID;
        _messageBody = messageBody;
    }
}

public class NetworkHandler
{
    public static NetworkHandler Instance = new NetworkHandler();
    public TcpClient _client = new TcpClient();
    public byte[] _buffer = new byte[GameConfig._bufferSize];
    public Queue<Message> _messageQueue = new Queue<Message>();
    public Queue<byte[]> _writeBuffer = new Queue<byte[]>();
    public State _state = State.None;

    public void Init()
    {
        string[] args = Environment.GetCommandLineArgs();
        for (int i = 1; i < args.Length; ++i)
        {
            if (args[i - 1] == "-h")
            {
                GameConfig._serverIP = args[i];
            }
            else if (args[i - 1] == "-p")
            {
                GameConfig._serverPort = int.Parse(args[i]);
            }
        }

        _client.SendTimeout = GameConfig._SendTimeout;
        _client.ReceiveTimeout = GameConfig._ReceiveTimeout;
        _client.NoDelay = GameConfig._NoDelay;

        _state = State.Init;
    }


    float _connectDeltatime = GameConfig._connectInterval;
    public void Connect()
    {
        _connectDeltatime += Time.deltaTime;
        if (_connectDeltatime >= GameConfig._connectInterval)
        {
            try
            {
                _client.BeginConnect(GameConfig._serverIP, GameConfig._serverPort, new AsyncCallback(Connecting), null);
            }
            catch (Exception e)
            {
                Debug.LogError(e);
            }
            _connectDeltatime = 0.0f;
        }
    }

    public void Disconnect()
    {
        if (_client.Connected)
        {
            _client.Close();
        }
        _state = State.Disconnect;
    }

    public void Connecting(IAsyncResult ar)
    {
        _client.EndConnect(ar);
        _state = State.Connect;
        Debug.Log("已连接上服务器。。。");

        try
        {
            _client.GetStream().BeginRead(_buffer, 0, _buffer.Length, new AsyncCallback(Reading), null);
            _state = State.Reading;
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }

    void Reading(IAsyncResult ar)
    {
        int readLen = _client.GetStream().EndRead(ar);
        int offset = 0;
        while (readLen >= 8)
        {
            Int32 messageLen = ReadInt32(_buffer, offset + 0);
            Int32 messageID = ReadInt32(_buffer, offset + 4);

            if (readLen >= 8 + messageLen)
            {
                byte[] messageBody = new byte[messageLen];
                Array.ConstrainedCopy(_buffer, offset + 8, messageBody, 0, messageLen);

                // lock(_messageQueue)
                _messageQueue.Enqueue(new Message(messageID, messageBody));

                readLen -= (8 + messageLen);
                offset += 8 + messageLen;
            }
            else
            {
                break;
            }
        }

        if (offset != 0)
        {
            Array.ConstrainedCopy(_buffer, offset, _buffer, 0, readLen);
        }

        try
        {
            _client.GetStream().BeginRead(_buffer, readLen, _buffer.Length - readLen, new AsyncCallback(Reading), null);
            _state = State.Reading;
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }

    public void Update()
    {
        if (_state == State.None)
        {
            Init();
        }
        else if (_state == State.Init)
        {
            Connect();
        }
        else
        {
            HandleMessage();
        }
    }

    public void HandleMessage()
    {
        Message message = null;
        lock (_messageQueue)
        {
            if (_messageQueue.Count > 0)
            {
                message = _messageQueue.Dequeue();
            }
            else
            {
                return;
            }
        }

        Protocol messageID = (Protocol)message._messageID;
        byte[] messageBody = message._messageBody;

        string str = "Receive: ";
        for (int i = 0; i < messageBody.Length; ++i)
        {
            str += string.Format("{0:X2} ", messageBody[i]);
        }
        Debug.Log(str);

        try
        {
            switch (messageID)
            {
                case Protocol.GAME_MSG_LOGON_SYNCPID:
                    {
                        Pb.SyncPid syncpid = Pb.SyncPid.Parser.ParseFrom(messageBody);
                        HeroController hero = GameObject.Find("Hero").GetComponent<HeroController>();
                        hero.OnLogon(syncpid);
                        break;
                    }
                case Protocol.GAME_MSG_BROADCAST:
                    {
                        Pb.BroadCast broadcast = Pb.BroadCast.Parser.ParseFrom(messageBody);
                        if (broadcast.Tp == 1)
                        {
                            // 聊天的广播
                            ChatController chat = GameObject.Find("Canvas").GetComponent<ChatController>();
                            chat.OnChat(broadcast);
                        }
                        else if (broadcast.Tp == 2)
                        {
                            // 玩家的初始位置
                            if (!GameConfig._heros.ContainsKey(broadcast.Pid) && !GameConfig._players.ContainsKey(broadcast.Pid))
                            {
                                try
                                {
                                    PlayerController player = GameObject.Instantiate(Resources.Load<GameObject>("Player")).GetComponent<PlayerController>();
                                    player.OnLogon(broadcast);
                                    player.OnUpdate(broadcast);
                                }
                                catch (Exception e)
                                {
                                    Debug.LogError(e);
                                }
                            }
                        }
                        else if (broadcast.Tp == 4)
                        {
                            // 广播某个玩家的新移动位置
                            if (GameConfig._players.ContainsKey(broadcast.Pid))
                            {
                                PlayerController player = GameConfig._players[broadcast.Pid];
                                player.OnUpdate(broadcast);
                            }
                        }
                        break;
                    }
                case Protocol.GAME_MSG_LOGOFF_SYNCPID:
                    {
                        Pb.SyncPid syncpid = Pb.SyncPid.Parser.ParseFrom(messageBody);
                        if (GameConfig._players.ContainsKey(syncpid.Pid))
                        {
                            PlayerController player = GameConfig._players[syncpid.Pid];
                            player.OnLogoff(syncpid);
                        }
                        break;
                    }
                case Protocol.GAME_MSG_SUR_PLAYER:
                    {
                        Pb.SyncPlayers players = Pb.SyncPlayers.Parser.ParseFrom(messageBody);
                        foreach (Pb.Player player in players.Ps)
                        {
                            Debug.Log("playerID = " + player.Pid + ", playerName = " + player.Username);
                            if (!GameConfig._heros.ContainsKey(player.Pid) && !GameConfig._players.ContainsKey(player.Pid))
                            {
                                PlayerController controller = GameObject.Instantiate(Resources.Load<GameObject>("Player")).GetComponent<PlayerController>();
                                controller.OnLogon(player);
                            }
                        }
                        break;
                    }
                case Protocol.GAME_MSG_CHANGE_WORLD_RESPONSE:
                    {
                        ChangeWorldResponse change = ChangeWorldResponse.Parser.ParseFrom(messageBody);
                        SceneHandler.Instance.OnChangeScene(change);
                        break;
                    }
                case Protocol.GAME_MSG_SKILL_BROAD:
                    {
                        Pb.SkillTrigger trigger = SkillTrigger.Parser.ParseFrom(messageBody);
                        if (GameConfig._players.ContainsKey(trigger.Pid))
                        {
                            PlayerController player = GameConfig._players[trigger.Pid];
                            player.OnTrigger(trigger);
                        }
                        break;
                    }
                case Protocol.GAME_MSG_SKILL_CONTACT_BROAD:
                    {
                        Pb.SkillContact skill = SkillContact.Parser.ParseFrom(messageBody);
                        if (GameConfig._heros.ContainsKey(skill.TargetPid))
                        {
                            HeroController hero = GameConfig._heros[skill.TargetPid];
                            hero.OnHurt(skill);
                        }
                        else if (GameConfig._players.ContainsKey(skill.TargetPid))
                        {
                            PlayerController player = GameConfig._players[skill.TargetPid];
                            player.OnHurt(skill);
                        }
                        break;
                    }
                default:
                    {
                        Debug.LogError("Unknown Protocol ID...");
                        break;
                    }
            }
        }
        catch (Exception e)
        {
            Debug.LogError(e);
        }
    }

    public Int32 ReadInt32(byte[] buffer, int offset)
    {
        Int32 ret = buffer[offset + 0] << 0
                  | buffer[offset + 1] << 8
                  | buffer[offset + 2] << 16
                  | buffer[offset + 3] << 24;
        return ret;
    }

    public void SendMessage(Protocol ID, byte[] message)
    {
        _writeBuffer.Enqueue(message);
        if (_state == State.None)
        {
            Init();
        }
        else if (_state == State.Init)
        {
            while (_writeBuffer.Count > GameConfig._writeBufferSize)
            {
                _writeBuffer.Dequeue();
            }

            Connect();
        }
        else
        {
            while (_writeBuffer.Count > 0)
            {
                byte[] msg = _writeBuffer.Dequeue();
                MemoryStream ms = new MemoryStream();
                BinaryWriter writer = new BinaryWriter(ms);
                writer.Write((Int32)msg.Length);
                writer.Write((Int32)ID);
                writer.Write(msg);
                writer.Flush();
                byte[] data = ms.ToArray();

                string str = "Send: ";
                for (int i = 0; i < msg.Length; ++i)
                {
                    str += string.Format("{0:X2} ", msg[i]);
                }
                Debug.Log(str);

                try
                {
                    _client.GetStream().BeginWrite(data, 0, data.Length, new AsyncCallback(Writting), null);
                    _state = State.Writting;
                }
                catch (Exception e)
                {
                    Debug.LogError(e);
                }
            }
        }
    }

    void Writting(IAsyncResult ar)
    {
        _client.GetStream().EndWrite(ar);
    }
}
