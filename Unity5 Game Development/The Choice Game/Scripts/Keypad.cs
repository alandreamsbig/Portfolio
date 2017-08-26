using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using UnityStandardAssets.Characters.FirstPerson;

public class Keypad : InteractableGroup, SignalRelay {

	public Canvas numberPad;
	public FirstPersonController player;

    public GameObject[] keypadNumbers;

	private string _doorCode;
	public Text rightOrWrong;
	private bool canInteract;

	public bool isCorrect = false;

    [Header("Keypad Lights")]
    [SerializeField]
    private GameObject _redLight;
    [SerializeField]
    private GameObject _yellowLight;
    [SerializeField]
    private GameObject _greenLight;

    protected override void OnInteract(bool rightClick = false) {
		base.OnInteract(rightClick);
		if (canInteract) {
			//GlobalController.player._camera._lookState = CameraController.LookState.Paused;
		}

		//Keypad keypad = new Keypad();
		//keypad.ButtonsEnabled
	}

	public override void OnCentered() {
		numberPad.gameObject.SetActive(true);
	}

	public override void OnUnCentered() {
		numberPad.gameObject.SetActive(false);
	}


	// Use this for initialization
	protected override void Start() {
		base.Start();
		_doorCode = "";
		canInteract = false;
	}

	// Update is called once per frame
	protected override void Update() {
		base.Update();
		if (numberPad.gameObject != null) { 
			if (Input.GetMouseButtonDown(1) && numberPad.gameObject.activeSelf) {
			}
		}

        if (canInteract) {
            if (Input.GetMouseButtonDown(0)) {
                Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
                RaycastHit hit;
                if (Physics.Raycast(ray, out hit)) {
                    for (int i = 0; i < keypadNumbers.Length; i++) {
                        if (hit.transform.name == keypadNumbers[i].name) {
                            _doorCode += i;
                            UpdateDoorCode();
                        }
                    }
                    if (hit.transform.name == "keypad_button_enter") {
                        EnterPressed();
                    }
                    if (hit.transform.name == "keypad_button_backspace") {
                        BackPressed();
                    }
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
		//player.m_MouseLook.XSensitivity = 2;
		//player.m_MouseLook.YSensitivity = 2;
		//GlobalController.SetCursorLock(true);
	}

	private void UpdateDoorCode() {
		rightOrWrong.text = _doorCode;
	}

	/*public void NumberPressed() {
		if (canInteract) {
			string number = EventSystem.current.currentSelectedGameObject.name;
			_doorCode += number;
			UpdateDoorCode();
		}
	}*/

	public void EnterPressed() {
		if (_doorCode == "8568") {
			rightOrWrong.text = "Correct";
			_doorCode = null;
			StartCoroutine(DelayForNumberPadDisappear());
            _yellowLight.GetComponent<Renderer>().material.DisableKeyword("_EMISSION");
            _greenLight.GetComponent<Renderer>().material.EnableKeyword("_EMISSION");
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

		//SetMouseSens();
		GlobalController.player._camera.ResetCenterTarget(wayPoint);
		isGroupActive = false;
		//GlobalController.player._camera._lookState = CameraController.LookState.FreeLook;
		isCorrect = true;
	}

	public void BackPressed() {
        if (_doorCode != null && _doorCode.Length > 0) {
            _doorCode = _doorCode.Substring(0, _doorCode.Length - 1);
        }
		UpdateDoorCode();
	}

	public void HandleSignal(int signal, SignalRelay sender) {
        if (signal > 0) {
            canInteract = true;
            _redLight.GetComponent<Renderer>().material.DisableKeyword("_EMISSION");
            _yellowLight.GetComponent<Renderer>().material.EnableKeyword("_EMISSION");
        }
        else {
            canInteract = false;
            _redLight.GetComponent<Renderer>().material.EnableKeyword("_EMISSION");
            _yellowLight.GetComponent<Renderer>().material.DisableKeyword("_EMISSION");
        }
	}
	
	public int RequestValue(SignalRelay asker) {
		return 0;
	}

	public GameObject GetGameObject() {
		return gameObject;
	}
}
