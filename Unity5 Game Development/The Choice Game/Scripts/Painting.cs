using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Painting : Interactables {

    public GameObject usableContainer;
    public GameObject key;

    public bool isKeyUsed = false;
	private Animator _animator;
    // Use this for initialization
    protected override void Start() {
        base.Start();
		_animator = GetComponent<Animator> ();
    }

    // Update is called once per frame
    protected override void Update () {
        if (Input.GetMouseButtonDown(0) && GlobalController.playerLookTarget != null) {
            if (_collider == GlobalController.playerLookTarget) {
                if (usableContainer.transform.childCount != 0 && key.transform != null) {
                    if (usableContainer.transform.GetChild(0) == key.transform) {
                        isKeyUsed = true;
                        //this.gameObject.SetActive(false);
						_animator.SetTrigger ("PaintOpen");
                    }
                }
            }
        }
    }
}
