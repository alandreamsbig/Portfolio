using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnButtons : MonoBehaviour {

	public GameObject[] myButton;
	public float lifeTime = 5f;


	// Use this for initialization
	void Start () {
		InvokeRepeating ("spawnButton", 1f, 4f);
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void spawnButton()
	{
		GameObject local = Instantiate (myButton [0], new Vector3 (167f, -215f, 0f), Quaternion.identity);
		Destroy (local, lifeTime);

	}

}
