using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public enum Protocol
{
    GAME_MSG_LOGON_SYNCPID = 1,
    GAME_MSG_TALK_CONTENT = 2,
    GAME_MSG_NEW_POSTION = 3,

    GAME_MSG_SKILL_TRIGGER = 4,
    GAME_MSG_SKILL_CONTACT = 5,
    GAME_MSG_CHANGE_WORLD = 6,

    GAME_MSG_BROADCAST = 200,
    GAME_MSG_LOGOFF_SYNCPID = 201,
    GAME_MSG_SUR_PLAYER = 202,
    GAME_MSG_SKILL_BROAD = 204,
    GAME_MSG_SKILL_CONTACT_BROAD = 205,
    GAME_MSG_CHANGE_WORLD_RESPONSE = 206,
}

public enum State
{
    None = 0,
    Init = 1,
    Dead = 2,
    Logon = 3,
    Logoff = 4,
    Move = 5,
    Rest = 6,
    Post = 7,
    Attack = 8,
    Update = 9,
    Connect = 10,
    Disconnect = 11,
    Reading = 12,
    Writting = 13,
    Load = 14
}

public class GameConfig
{
    public static string _serverIP = "192.168.12.142";
    public static int _serverPort = 8899;
    public static int _SendTimeout = 1000;
    public static int _ReceiveTimeout = 1000;
    public static bool _NoDelay = true;
    public static float _connectInterval = 60 * 1000.0f;
    public static float _postInterval = 1.0f;

    public static int _bufferSize = 8192;
    public static int _writeBufferSize = 100;

    public static int _desertSceneID = 1;
    public static int _roomSceneID = 2;
    public static int _sceneID = _desertSceneID;

    public static float _roleSpeed = 5.0f;
    public static float _heroNameAdjust = 2.4f;
    public static float _bloodValueAdjust = 2.2f;
    public static int _bulletID = 0;
    public static float _bulletSpeed = 50.0f;
    public static float _bulletAdjust = 1.02f;
    public static float _bulletOffset = 1.5f;
    public static float _rotateSpeed = 10.0f;
    public static int _chatLinesMax = 10;

    public static Dictionary<int, HeroController> _heros = new Dictionary<int, HeroController>();
    public static Dictionary<int, PlayerController> _players = new Dictionary<int, PlayerController>();
}
