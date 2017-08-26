﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ropeCollect2 : MonoBehaviour {


	public float time = 4f;
	private GameObject ropee;
	private Collider collide;

	public bool hasItem;


	void Start(){

		ropee = GameObject.FindWithTag ("ropeCollide2");
		collide = ropee.GetComponent<BoxCollider> ();
		collide.enabled = false;
	}

	void Update()
	{


		if(Input.GetKey("f") && hasItem)
		{
			collide.enabled = true;
			Destroy (collide, time);
			hasItem = false;

		}

	}

	//use trigger or Collision
	void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "rope") {
			Debug.Log ("omg");
			Destroy(col.gameObject);
			hasItem = true;

		}


	}
}
