using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drawer1Open :Interactables {


	private Animator _animator;
	// Use this for initialization
	private bool isClosed;




	// Use this for initialization
	protected override void Start() {
		_renderer = GetComponent<MeshRenderer>();
		_collider = GetComponent<Collider>();
		_animator = GetComponent<Animator>();
		isClosed = true;
	}

	protected override void OnInteract(bool rightClick = false) {

		if (!rightClick) {
			if (isClosed)
				_animator.SetTrigger("Draw1Open");
			else
				_animator.SetTrigger("Draw1Close");
			isClosed = !isClosed;
		}
	
	}
	
}
