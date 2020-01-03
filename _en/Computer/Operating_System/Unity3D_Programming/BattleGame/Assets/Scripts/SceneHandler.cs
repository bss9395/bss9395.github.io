using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using Google.Protobuf;
using Pb;

public class SceneHandler
{
    public static SceneHandler Instance = new SceneHandler();
    public static int _sceneID = 0;
    public Pb.BroadCast _broadcast = new Pb.BroadCast();
    public State _state = State.None;

    public void Update()
    {
        if (_state == State.Load)
        {
            Load();
        }
    }


    public void OnChangeScene(Pb.ChangeWorldResponse change)
    {
        if (change.ChangeRes == 1)
        {
            _sceneID = change.TargetId;
            HeroController oldHero = GameObject.Find("Hero").GetComponent<HeroController>();
            _broadcast.Pid = oldHero._heroID;
            _broadcast.Username = oldHero._heroName.text;
            _broadcast.P = change.P;
            _broadcast.Tp = 2;

            string sceneName = "";
            if (change.TargetId == 1)
            {
                sceneName = "WorldScene";
            }
            else if (change.TargetId == 2)
            {
                sceneName = "BattleScene";
            }
            else
            {
                Debug.LogError("Unkown Target Scene ID...");
            }
            AsyncOperation async = SceneManager.LoadSceneAsync(sceneName);
            async.completed += SceneLoading;
        }
    }

    public void SceneLoading(AsyncOperation async)
    {
        async.allowSceneActivation = true;
        _state = State.Load;
    }

    public void Load()
    {
        // if(_sceneID == 2)
        HeroController newHero = GameObject.Find("Hero").GetComponent<HeroController>();
        newHero.OnLogon(_broadcast);
        _state = State.None;
    }
}
