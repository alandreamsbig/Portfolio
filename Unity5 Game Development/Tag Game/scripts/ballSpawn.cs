﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ballSpawn : MonoBehaviour {

	public GameObject ball;
	public float lifeTime = 4f;

    public float spawnXMin;
    public float spawnXMax;



	// Use this for initialization
	void Start () {
		InvokeRepeating("SpawnAgent",1,8);	

	}


	void SpawnAgent()
	{
		GameObject local = Instantiate (ball, new Vector3(Random.Range(-16f,16f), 0.3f, Random.Range(-8f,8f)), Quaternion.Euler(90, 0, 0));
		Destroy (local, lifeTime);


	}

	// Update is called once per frame
	void Update () {



	}
}
