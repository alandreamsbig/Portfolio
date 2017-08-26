using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class GlobalController : MonoBehaviour {

	public bool _isPaused;
	private static bool _mouseLock;

	public static PlayerController player;
	public static Collider playerLookTarget;
	public static UICursor _uiCursor;

	public Collider playerLookTargetDummy;


	// Use this for initialization
	void Start() {
		var uiCursor = GetComponent<UICursor>();

		if (uiCursor != null) {
			_uiCursor = uiCursor;
		}
		//_isPaused = false;
		//SetCursorLock(true);
	}

	public static void SetCursorLock(bool locked) {
		//_mouseLock = locked;
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.Escape)) {
			//_isPaused = !_isPaused;
			//SetCursorLock(!_isPaused);
		}
		playerLookTargetDummy = playerLookTarget;
		
		
		//Cursor.lockState = (_mouseLock) ? CursorLockMode.Locked : CursorLockMode.None;

		//Cursor.visible = true;

		if (_isPaused || Cursor.lockState == CursorLockMode.None) {
			//Cursor.lockState = CursorLockMode.None;
		} else {
			//Cursor.lockState = CursorLockMode.Locked;
			//Cursor.visible = false;
		}
	}
}
