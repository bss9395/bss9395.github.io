using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class CameraController : MonoBehaviour
{
    public GameObject _hero = null;

    public Vector3 _angle = new Vector3(0.0f, 0.0f, 0.0f);
    public Vector3 _angleMax = new Vector3(60.0f, 60.0f, 60.0f);
    public Vector3 _adjust = new Vector3(0.0f, 1.02f, 0.0f);
    public float _distance = 5.0f;

    private void Start()
    {
        if (_hero == null)
        {
            throw new NotImplementedException();
        }
    }

    void Update()
    {
        _angle.x += Input.GetAxis("Mouse X");
        _angle.y += Input.GetAxis("Mouse Y");

        if (_angle.y > _angleMax.y)
        {
            _angle.y = _angleMax.y;
        }
        else if (_angle.y < -_angleMax.y)
        {
            _angle.y = -_angleMax.y;
        }

        this.transform.rotation = Quaternion.Euler(_angle.y, _angle.x, 0);
        this.transform.position = _hero.transform.position - (this.transform.forward * _distance);
    }
}
