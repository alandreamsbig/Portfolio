using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using UnityStandardAssets.Characters.FirstPerson;

public class SafePad : Interactables {

	public Canvas numberPad;
	public FirstPersonController player;

	private string _doorCode;
	public Text rightOrWrong;

	protected override void OnInteract(bool rightClick = false) {
		numberPad.gameObject.SetActive(true);

		player.m_MouseLook.XSensitivity = 0;
		player.m_MouseLook.YSensitivity = 0;

		//GlobalController.SetCursorLock(false);

		//Keypad keypad = new Keypad();
		//keypad.ButtonsEnabled();
	}

	// Use this for initialization
	protected override void Start() {
		base.Start();
	}

	// Update is called once per frame
	protected override void Update() {

		base.Update();
		if (numberPad.gameObject != null) { 
			if (Input.GetMouseButtonDown(1) && numberPad.gameObject.activeSelf) {
				numberPad.gameObject.SetActive(false);
				GlobalController.player._camera._lookState = CameraController.LookState.FreeLook;
				if (player != null) {
					//SetMouseSens();
				}
			}
		}
	}

	void OnMouseEnter() {
		//startcolor = renderer.material.color;
		//if (_renderer != null) {
		//	_renderer.material.color = Color.yellow;
		//}
		//Debug.Log("HI");
	}

	void OnMouseExit() {
		//renderer.material.color = startcolor;
	}

	private void SetMouseSens() {
		player.m_MouseLook.XSensitivity = 2;
		player.m_MouseLook.YSensitivity = 2;
		//GlobalController.SetCursorLock(true);
	}

	private void UpdateDoorCode() {
		rightOrWrong.text = _doorCode;
	}

	public void NumberPressed() {
		string number = EventSystem.current.currentSelectedGameObject.name;
		_doorCode += number;
		UpdateDoorCode();
	}

	public void EnterPressed() {
		if (_doorCode == "358") {
			rightOrWrong.text = "Correct";
			_doorCode = null;
			StartCoroutine(DelayForNumberPadDisappear());
		}
		else {
			rightOrWrong.text = "Wrong";
			_doorCode = null;
		}
		rightOrWrong.gameObject.SetActive(true);
	}

	IEnumerator DelayForNumberPadDisappear() {
		yield return new WaitForSeconds(1.5f);
		numberPad.gameObject.SetActive(false);
		SetMouseSens();
	}

	public void BackPressed() {
		_doorCode = _doorCode.Substring(0, _doorCode.Length - 1);
		UpdateDoorCode();
	}
}
