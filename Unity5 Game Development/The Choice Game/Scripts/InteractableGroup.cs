using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InteractableGroup : Interactables {

	public Transform wayPoint;
	public bool isGroupActive;

	protected override void Start () {
		base.Start();
		foreach (Transform t in gameObject.GetComponentsInChildren<Transform>()) {
			if (t.tag == "waypoint") {
				wayPoint = t;
			}
		}
	}
	
	protected override void Update () {
		base.Update();
		
		if (Input.GetMouseButtonDown(1) && isGroupActive) {
			ResetCenter();
		}
	}

	protected virtual void ResetCenter() {
		GlobalController.player._camera.ResetCenterTarget(wayPoint);
		isGroupActive = false;
	}

	protected override void OnInteract(bool rightClick = false) {
		base.OnInteract();
		if (rightClick)
			return;

		if (!isGroupActive) {
			GlobalController.player._camera.SetCenterTarget(wayPoint, this);
			isGroupActive = true;

		}
	}

	protected override void OnGUI() {
		if (!isGroupActive) {
			base.OnGUI();
		}
	}


	public virtual void OnCentered() { }
	public virtual void OnUnCentered() { }

}
