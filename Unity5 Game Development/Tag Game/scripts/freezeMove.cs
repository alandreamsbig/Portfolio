using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class freezeMove : MonoBehaviour {

	public GameObject player;
	public Rigidbody rb; 

	// Use this for initialization
	void Start () {
		player = GameObject.Find("player1");
		//Debug.Log (player);
		rb = player.GetComponent<Rigidbody> ();
	}

	void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "IT") {
			Debug.Log ("in");
			col.gameObject.SetActive (false);
			Freeze ();


		}


	}

	
	// Update is called once per frame
	IEnumerator  Freeze() {
		
		rb.constraints = RigidbodyConstraints.FreezeAll;
		yield return new WaitForSeconds(3);
		rb.constraints = RigidbodyConstraints.None;
	
	}
}
