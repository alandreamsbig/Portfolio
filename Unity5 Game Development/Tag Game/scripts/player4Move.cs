using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player4Move : MonoBehaviour {

	public float speed = 0.2f;
	public float boost = 0.25f;

	void Update()
	{
		if (gameObject.tag == "IT") {
			if (Input.GetKey (KeyCode.Keypad8)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + boost);
			}
			if (Input.GetKey (KeyCode.Keypad4)) {
				transform.position = new Vector3 (transform.position.x - boost, transform.position.y, transform.position.z);
			}
			if (Input.GetKey (KeyCode.Keypad5)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - boost);
			}
			if (Input.GetKey (KeyCode.Keypad6)) {
				transform.position = new Vector3 (transform.position.x + boost, transform.position.y, transform.position.z);
			}
		} else {

			if (Input.GetKey (KeyCode.Keypad8)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + speed);
			}
			if (Input.GetKey (KeyCode.Keypad4)) {
				transform.position = new Vector3 (transform.position.x - speed, transform.position.y, transform.position.z);
			}
			if (Input.GetKey (KeyCode.Keypad5)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - speed);
			}
			if (Input.GetKey (KeyCode.Keypad6)) {
				transform.position = new Vector3 (transform.position.x + speed, transform.position.y, transform.position.z);
			}


		}
	}
}
