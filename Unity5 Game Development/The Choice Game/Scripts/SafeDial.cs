using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SafeDial : InteractableGroup {

	public float speed = 80f;

	//public AudioClip tok;
	//public AudioSource audio;
	public Transform[] safeDials;
	//public GameObject dial1;
	public Text SafeOpen;

	private float _angle1;
	private float _angle2;
	private float _angle3;
	private Animation _animation;
	private Animator _animator;
	float[] remainingAngleOffset = {0f,0f,0f};


	protected override void Start(){
		base.Start();
		//audio = GetComponent<AudioSource> ();
		Transform[] safeDials = GetComponentsInChildren<Transform> ();
		if (SafeOpen != null)
			SafeOpen.text = "";
		_animator = GetComponent<Animator> ();
	}



	protected override void Update(){
		base.Update();
		//Debug.Log (safeDials[0]);
		if (Input.GetMouseButtonDown (0) && GlobalController.playerLookTarget != null) {
			

			for (int i = 0; i < 3; i++) {
				if (safeDials [i] == null)
					continue;
				if (safeDials [i].Equals (GlobalController.playerLookTarget.transform)) {
					remainingAngleOffset [i] -= 30f;
				
				}
			
			
				//Ray ray = Camera.main.ScreenPointToRay (Input.mousePosition);
				//RaycastHit hit;
				//if (Physics.Raycast (ray, out hit)) {
				//	if (hit.transform.name == "safe_dial_l") {
				//		Debug.Log (hit.transform.name);
				//		if (Input.GetKey (KeyCode.LeftControl)) {
				//			safeDials [0].transform.Rotate (new Vector3 (0, 0, -Time.deltaTime * speed));

				//		}
				//	} else if (hit.transform.name == "safe_dial_m") {
				//		Debug.Log (hit.transform.name);
				//		if (Input.GetKey (KeyCode.LeftControl)) {
				//			safeDials [1].transform.Rotate (new Vector3 (0, 0, -Time.deltaTime * speed));
				//		}
				//	} else if (hit.transform.name == "safe_dial_r") {
				//		Debug.Log (hit.transform.name);
				//		if (Input.GetKey (KeyCode.LeftControl)) {
				//			safeDials [2].transform.Rotate (new Vector3 (0, 0, -Time.deltaTime * speed));
				//		}
				//	}
				//}
			}
		}
		for (int j = 0; j < 3; j++){
			
			safeDials[j].Rotate(new Vector3(0, 0, remainingAngleOffset[j]/4f));
			remainingAngleOffset[j] *= 3f /4f;
		}
		
		_angle1 = safeDials[0].transform.rotation.eulerAngles.z;
		_angle2 = safeDials[1].transform.rotation.eulerAngles.z;
		_angle3 = safeDials[2].transform.rotation.eulerAngles.z;


		if (_angle1 > 328 && _angle1 < 332 && _angle2 > 237 && _angle2 < 250 && _angle3 > 118 && _angle3 < 122) {
		
			_animator.SetTrigger("open");

			if (isGroupActive) {
				this.GetComponent<BoxCollider>().enabled = false;
				GlobalController.player._camera.ResetCenterTarget(wayPoint);
				isGroupActive = false;
			}
		}



	}
}
