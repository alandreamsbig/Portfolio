using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class Examinables : MonoBehaviour {
	
	public GameObject examinable;
	public Camera mainCamera;
	public Camera zoomCamera;
	
	private Collider _collider;
	private Transform _wayPoint;
	
	float rotSpeed = 200f;
	float pitch = 0f;
	float yaw = 0f;
	
	Quaternion startRotation;
	Vector3 startPosition;
	
	// Use this for initialization
	void Start() { 
		zoomCamera.enabled = false;
		
		_collider = GetComponent<Collider>();
		foreach (Transform t in gameObject.GetComponentsInChildren<Transform>()) {
			if (t.tag == "waypoint") {
				_wayPoint = t;
			}
		}
		startRotation = transform.rotation;
		startPosition = transform.position;
	}

	// Update is called once per frame
	void Update() {
		if (Input.GetMouseButtonDown(0)) {
			if (GlobalController.player._camera._lookState == CameraController.LookState.FreeLook && _collider == GlobalController.playerLookTarget) {
				GlobalController.player._camera.zoomYaw = 0f;
				GlobalController.player._camera.zoomPitch = 0f;
			
				zoomCamera.enabled = true;
				GlobalController.player._camera.SetExamineTarget(transform, _wayPoint.transform);
			}
		}
		
		if (zoomCamera.enabled) {
			//yaw += Input.GetAxis("Mouse X") * rotSpeed * Mathf.Deg2Rad;
			//pitch += Input.GetAxis("Mouse Y") * rotSpeed * Mathf.Deg2Rad;
			
			//if (yaw > 360f) {
			//	yaw -= 360f;
			//}
			//if (yaw < -360f) {
			//	yaw += 360f;
			//}
			//pitch = Mathf.Clamp(pitch, -90f, 90f);
			
		}
		
		
		if (GlobalController.player._camera._lookState == CameraController.LookState.Examining && Input.GetMouseButtonDown(1)) {
			zoomCamera.enabled = false;
			GlobalController.player._camera.SetExamineTarget(null, null);
		}
	}


	protected virtual void OnGUI() {
		if (GlobalController.playerLookTarget == _collider) {
			GlobalController._uiCursor.drawExaminable();
		}
	}
}
