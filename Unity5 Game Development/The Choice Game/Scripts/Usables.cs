using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Usables : MonoBehaviour {

	public Camera mainCamera;

	public GameObject usable;
	public GameObject usableContainer;
	public GameObject originalParent;

	private Collider _collider;

	// Use this for initialization
	void Start () {
		_collider = GetComponent<BoxCollider>();
	}

	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown(0)) {
			Ray rays = mainCamera.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(rays, out hit)) {
				if (hit.transform.name == usable.name) {
					if(usableContainer.transform.childCount == 0) {
						usable.transform.SetParent(usableContainer.transform);
						//usable.transform.localPosition = new Vector3(usable.transform.localPosition.x + 2.0f, usable.transform.localPosition.y, usable.transform.localPosition.z);
                        usable.GetComponent<BoxCollider>().enabled = false;
					} else {
						Transform currentUsable = usableContainer.transform.GetChild(0);
						currentUsable.SetParent(originalParent.transform);
						usable.transform.SetParent(usableContainer.transform);
						//usable.transform.localPosition = new Vector3(usable.transform.localPosition.x + 2.0f, usable.transform.localPosition.y - 0.3f, usable.transform.localPosition.z);
                        currentUsable.GetComponent<BoxCollider>().enabled = true;
                        usable.GetComponent<BoxCollider>().enabled = false;
                    }
				}
			}
		}

        if(Input.GetMouseButtonDown(1) && usableContainer.transform.childCount > 0) {
            Transform currentUsable = usableContainer.transform.GetChild(0);
            currentUsable.SetParent(originalParent.transform);
            currentUsable.GetComponent<BoxCollider>().enabled = true;
        }

    }


	protected virtual void OnGUI() {
		if (GlobalController.playerLookTarget == _collider) {
			GlobalController._uiCursor.drawUsable();
		}
	}


}
