using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SpawnRock : MonoBehaviour {

	public float lifeTime = 5f;

	public GameObject[] Rock;
	private Transform player;
	private Vector3 offset;
	private Vector3 off = new Vector3(10,5,0);
	public Button RockButton;

	// Use this for initialization
	void Start () {
		
		Button btn = RockButton.GetComponent<Button> ();
		btn.onClick.AddListener (spawnRock);
		player = GameObject.FindGameObjectWithTag("Player").transform;
		offset = Camera.main.transform.position - player.transform.position;

	}
	
	// Update is called once per frame
	void Update () {
	}

	void spawnRock()
	{
		GameObject local = Instantiate (Rock [0], (Camera.main.transform.position - off) - offset,Quaternion.identity);
		Destroy (local, lifeTime);

	}
}
