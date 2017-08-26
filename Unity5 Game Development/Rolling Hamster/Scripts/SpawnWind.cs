using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SpawnWind : MonoBehaviour {

	public float lifeTime = 5f;

	public GameObject[] Wind;
	private Transform player;
	private Vector3 offset;
	private Vector3 off = new Vector3(5,5,0);
	public Button WindButton;

	// Use this for initialization
	void Start () {

		Button btn = WindButton.GetComponent<Button> ();
		btn.onClick.AddListener (spawnWind);
		player = GameObject.FindGameObjectWithTag("Player").transform;
		offset = Camera.main.transform.position - player.transform.position;

	}

	// Update is called once per frame
	void Update () {
		
	}

	void spawnWind()
	{
		GameObject local = Instantiate (Wind [0], (Camera.main.transform.position - off) - offset,Quaternion.identity);
		Destroy (local, lifeTime);

	}
}
