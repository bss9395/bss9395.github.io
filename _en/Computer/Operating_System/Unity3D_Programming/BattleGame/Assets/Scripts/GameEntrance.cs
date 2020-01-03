using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameEntrance : MonoBehaviour
{
    void Update()
    {
        NetworkHandler.Instance.Update();
        SceneHandler.Instance.Update();
    }
}
