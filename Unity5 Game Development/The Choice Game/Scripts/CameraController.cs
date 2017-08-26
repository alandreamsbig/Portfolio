using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class CameraController : MonoBehaviour {

	public enum LookState {
		FreeLook,
		Examining,
		ZoomingIn,
		ZoomedIn,
		ZoomingOut,
		Paused
	}
	
	public Camera mainCamera;
	public Camera zoomCamera;
	
	public FirstPersonController player;
	
	public float playerPitch;
	public float playerYaw;

	[SerializeField]
	float zoomMouseSensitivity;
	[SerializeField]
	float lookMouseSensitivity;

	float mouseSensitivity;

	public LookState _lookState;
	LookState _storedLookState;
	
	public float zoomPitch = 0f;
	public float zoomYaw = 0f;

	private Vector3 examiningSourcePosition;
	private Quaternion examiningSourceRotation;
	private Vector3 examiningTargetPosition;
	private Quaternion examiningTargetRotation;

	public float centering;
	private InteractableGroup centeringGroup;
	private Vector3 centeringSourcePosition;
	private Quaternion centeringSourceRotation;
	private Vector3 centeringTargetPosition;
	private Quaternion centeringTargetRotation;
	float centeringTime;

	// Use this for initialization
	void Start () {
		mainCamera.enabled = true;
		zoomCamera.enabled = false;

		mouseSensitivity = lookMouseSensitivity;

		_lookState = LookState.FreeLook;
	}
	
	void Update () {
		//Debug.Log(_lookState.ToString());

		switch (_lookState) {
			case LookState.FreeLook:
				Cursor.lockState = CursorLockMode.Locked;
				playerYaw += Input.GetAxis("Mouse X") * lookMouseSensitivity * Mathf.Deg2Rad;
				playerPitch += Input.GetAxis("Mouse Y") * lookMouseSensitivity * Mathf.Deg2Rad;
				transform.rotation = Quaternion.identity;
				transform.Rotate(new Vector3(-playerPitch, playerYaw, 0), Space.World);
				transform.Rotate(new Vector3(0, 0, BoatTilt._tiltAngle), Space.World);
				break;
			case LookState.Examining:
				Cursor.lockState = CursorLockMode.Locked;
				zoomYaw += Input.GetAxis("Mouse X") * zoomMouseSensitivity * Mathf.Deg2Rad;
				zoomPitch += Input.GetAxis("Mouse Y") * zoomMouseSensitivity * Mathf.Deg2Rad;
				zoomPitch = Mathf.Clamp(zoomPitch, -90f, 90f);

				zoomCamera.transform.rotation = examiningSourceRotation;
				zoomCamera.transform.position = examiningSourcePosition;
				zoomCamera.transform.RotateAround(examiningTargetPosition, zoomCamera.transform.up, zoomYaw);
				zoomCamera.transform.RotateAround(examiningTargetPosition, zoomCamera.transform.right, -zoomPitch);
				break;
			case LookState.ZoomedIn:
				Cursor.lockState = CursorLockMode.None;
				break;
			case LookState.ZoomingIn:
			case LookState.ZoomingOut:
				Cursor.lockState = CursorLockMode.Locked;
				transform.position = (centeringSourcePosition * centering) + (centeringTargetPosition * (1f - centering));
				transform.rotation = Quaternion.Lerp(centeringSourceRotation, centeringTargetRotation, (1f - centering));
				if (centering > .02f) {
					centering -= .01f;
				} else {
					centering = 0f;
					if (_lookState == LookState.ZoomingIn) {
						_lookState = LookState.ZoomedIn;
						if (centeringGroup != null) {
							centeringGroup.OnCentered();
						}
					} else if (_lookState == LookState.ZoomingOut) {
						_lookState = LookState.FreeLook;
					}
				}

				break;
			case LookState.Paused:
				Cursor.lockState = CursorLockMode.None;
				break;
		}

		if (Input.GetKeyDown(KeyCode.Escape)) {
			if (_lookState == LookState.Paused) {
				_lookState = _storedLookState;
			} else {
				_storedLookState = _lookState;
				_lookState = LookState.Paused;
			}
		}


		playerPitch = Mathf.Clamp(playerPitch, -90f, 90f);

		if (Input.GetMouseButtonDown(1)) {
			mainCamera.enabled = true;
			zoomCamera.enabled = false;
		}
	}
	
	void LateUpdate () {
		Ray rays = mainCamera.ScreenPointToRay(Input.mousePosition);
		RaycastHit hit;
		if (Physics.Raycast(rays, out hit)) {
			GlobalController.playerLookTarget = hit.collider;
		} else {
			GlobalController.playerLookTarget = null;
		}
	}

	public void SetCenterTarget(Transform target, InteractableGroup group) {
		Debug.Log("setting");
		if (_lookState == LookState.FreeLook) {
			_lookState = LookState.ZoomingIn;
			centering = 1f;
			centeringGroup = group;
			centeringTargetPosition = target.position;
			centeringTargetRotation = target.rotation;
			centeringSourcePosition = transform.position;
			centeringSourceRotation = transform.rotation;
		}
	}

	public void ResetCenterTarget(Transform target) {
		Debug.Log("resetting");
		if (_lookState == LookState.ZoomedIn) {
			_lookState = LookState.ZoomingOut;
			centering = 1f;
			if (centeringGroup != null) {
				centeringGroup.OnUnCentered();
			}
			centeringTargetPosition = centeringSourcePosition;
			centeringTargetRotation = centeringSourceRotation;
			centeringSourcePosition = target.position;
			centeringSourceRotation = target.rotation;
		}
	}

	public void SetExamineTarget(Transform to, Transform from) {
		if (to == null) {
			_lookState = LookState.FreeLook;
			return;
		}
		_lookState = LookState.Examining;
		examiningSourcePosition = from.position;
		examiningSourceRotation = from.rotation;
		examiningTargetPosition = to.position;
		examiningTargetRotation = to.rotation;
	}
}
