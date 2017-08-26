using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoatTilt : MonoBehaviour {
	public static float _tiltAngle;
	public float myAngle;
	/*
	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

		StartCoroutine(RotateMe(Vector3.right * 20, 5));
	}

	IEnumerator RotateMe(Vector3 byAngles, float inTime) {
		var fromAngle = transform.rotation;
		var toAngle = Quaternion.Euler(transform.eulerAngles + byAngles);
		for(var t = 0f; t < 1; t += Time.deltaTime/inTime) {
			transform.rotation = Quaternion.Lerp(fromAngle, toAngle, t);
			yield return null;
		}
	}
	*/

	//Increase this value to decrease the tilt speed
	public float boatTiltSpeed = 0.1f;

	IEnumerator LoopRotation(float angle) {
		for (int i = 0; i < 3; i++) {
			transform.Rotate(new Vector3(0, 0, Mathf.Sin(Time.time / boatTiltSpeed)), Space.World);
			yield return null;
	
		}
	}


	void Update() {
		myAngle = _tiltAngle;
		//StartCoroutine(LoopRotation(10f));
	}

	void LateUpdate() {
		_tiltAngle = 5f * Mathf.Sin(Time.time * boatTiltSpeed);
	}

	/*
	float rotationAmount = 20.0f;
	void Update(){
		Vector3 rot = transform.rotation.eulerAngles;
		rot.z = rot.z + rotationAmount * Time.deltaTime;
		if (rot.z > 360)
			rot.z -= 360;
		else if (rot.y < 360)
			rot.z += 360;
		transform.eulerAngles = rot;
	}


	public float period;
	public float maxRotation;
	private float _Time;


	void Update(){
		_Time = _Time + Time.deltaTime;
		float phase = Mathf.Sin (_Time / period);
		transform.rotation = Quaternion.Euler (0, 0, Mathf.Sin (Time.realtimeSinceStartup) * 70);
		//Debug.Log (transform.rotation);

	}

	*/
}
