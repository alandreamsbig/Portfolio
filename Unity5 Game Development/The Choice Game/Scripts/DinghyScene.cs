using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DinghyScene : InteractableGroup {

	public Texture _overlay;
	private float timeSinceActivation = 0f;

	// Use this for initialization
	protected override void Start() {
		base.Start();
	}


	protected override void Update() {
		base.Update();

		if (isGroupActive) {
			timeSinceActivation += Time.deltaTime;
		}
	}


	// Update is called once per frame
	protected override void ResetCenter() {

	}
	
	protected override void OnInteract(bool rightClick = false) {
		if (rightClick)
			return;
		base.OnInteract();
	}

	public override void OnCentered() {
		
	}
	


	protected override void OnGUI() {



		if (isGroupActive) {
			Texture2D texture = new Texture2D(1, 1);
			texture.SetPixel(0, 0, new Color(0f, 0f, 0f, timeSinceActivation / 5f));
			texture.Apply();
			GUI.skin.box.normal.background = texture;
			GUI.Box(new Rect(0, 0, Screen.width, Screen.height), GUIContent.none);
			//GUI.DrawTexture(new Rect(0, 0, Screen.width, Screen.height), _overlay, ScaleMode.StretchToFill, true)
		}
	}

}
