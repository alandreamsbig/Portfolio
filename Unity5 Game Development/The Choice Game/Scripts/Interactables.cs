using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Interactables : MonoBehaviour {

	protected MeshRenderer _renderer;
	protected Collider _collider;

	protected virtual void OnInteract(bool rightClick = false) { }

	// Use this for initialization
	protected virtual void Start() {
		_renderer = GetComponent<MeshRenderer>();
		_collider = GetComponent<Collider>();
	}

	// Update is called once per frame
	protected virtual void Update() {
		if (Input.GetMouseButtonDown(0) && GlobalController.playerLookTarget != null) {
			if (_collider == GlobalController.playerLookTarget) {
				OnInteract();
			}
		}
		if (Input.GetMouseButtonDown(1) && GlobalController.playerLookTarget != null) {
			if (_collider == GlobalController.playerLookTarget) {
				OnInteract(true);
			}
		}
	}

	protected virtual void OnGUI() {
		if (GlobalController.playerLookTarget == _collider) {
			GlobalController._uiCursor.drawInteractable();
		}
	}

	private Color startcolor;
	void OnMouseEnter() {
		//startcolor = renderer.material.color;
		//if (_renderer != null)
			//_renderer.material.color = Color.yellow;
	}

	void OnMouseExit() {
		//renderer.material.color = startcolor;
	}
}
