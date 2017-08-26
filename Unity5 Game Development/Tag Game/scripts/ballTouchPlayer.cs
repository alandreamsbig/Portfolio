using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ballTouchPlayer : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void OnCollisionEnter(Collision col)
	{
		if (col.gameObject.tag == "Player")
		{
			//elapsedTime = elapsedTime - 1f;
			Debug.Log("muahaha");

			col.gameObject.tag = "IT";

			// Debug.Log("Not it!");
		}

		else if (col.gameObject.tag == "IT")
		{
			col.gameObject.tag = "Player";
			//rb.AddForce (this.gameObject.transform.position * thrust);
		}
	}
}
