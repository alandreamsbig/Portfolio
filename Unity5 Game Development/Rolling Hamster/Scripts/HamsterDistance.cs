using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections;

public class HamsterDistance : MonoBehaviour
{
    [SerializeField]
    public Text DistText;
    public float DistanceMod = 2f;
    private float range = 10.0f;

    private Transform t;
    private Transform player;

    private void Awake()
    {
        t = this.transform;
        player = GameObject.FindGameObjectWithTag("Player").transform;
    }

    private void Update()
    {
        if (player)
            DistText.text = (Mathf.Round(Distance() / DistanceMod)).ToString() + " Ft";
        else
            DistText.text = "GONE!?";
    }

    private float Distance()
    {
        return Vector3.Distance(t.position, player.position);
    }
}