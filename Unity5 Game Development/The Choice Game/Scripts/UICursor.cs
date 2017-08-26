using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UICursor : MonoBehaviour {

	public Texture _default, _usable, _interactable, _examinable;
	private int screenWidth, screenHeight;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		screenWidth = Camera.main.pixelWidth / 2;
		screenHeight = Camera.main.pixelHeight / 2;
	}
	
	void OnGUI () {

		if (GlobalController.player._camera._lookState == CameraController.LookState.FreeLook)
			GUI.DrawTexture(new Rect(screenWidth - 16, screenHeight - 16, 32, 32), _default, ScaleMode.ScaleToFit);
	}

	public void drawUsable() {
		GUI.DrawTexture(new Rect(screenWidth - 16, screenHeight + 48, 32, 32), _usable, ScaleMode.ScaleToFit);
	}

	public void drawInteractable() {
		GUI.DrawTexture(new Rect(screenWidth - 16, screenHeight + 48, 32, 32), _interactable, ScaleMode.ScaleToFit);
	}

	public void drawExaminable() {
		if (GlobalController.player._camera._lookState != CameraController.LookState.Examining)
			GUI.DrawTexture(new Rect(screenWidth - 16, screenHeight + 48, 32, 32), _examinable, ScaleMode.ScaleToFit);
	}
}
