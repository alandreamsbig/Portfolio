using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drawer2Open : Interactables {

	private Animator _animator;
	// Use this for initialization





	// Use this for initialization
	protected override void Start() {
		_renderer = GetComponent<MeshRenderer>();
		_collider = GetComponent<Collider>();
		_animator = GetComponent<Animator> ();
	}

	protected override void OnInteract(bool rightClick = false) {
		Debug.Log ("Draw2Open");
		if (!rightClick) {
			
			_animator.SetTrigger ("Draw2Open");
			_animator.SetTrigger ("Draw2Close");
		}

	}
}
