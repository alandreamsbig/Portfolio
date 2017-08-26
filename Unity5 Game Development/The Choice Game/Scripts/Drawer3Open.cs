using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drawer3Open : Interactables {

	private Animator _animator;
	// Use this for initialization





	// Use this for initialization
	protected override void Start() {
		_renderer = GetComponent<MeshRenderer>();
		_collider = GetComponent<Collider>();
		_animator = GetComponent<Animator> ();
	}

	protected override void OnInteract(bool rightClick = false) {
		Debug.Log ("Draw3Open");
		if (!rightClick) {
			
			_animator.SetTrigger ("Draw3Open");
			_animator.SetTrigger ("Draw3Close");
		}

	}
}
