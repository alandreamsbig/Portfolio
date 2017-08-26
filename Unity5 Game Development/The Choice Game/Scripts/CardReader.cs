using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardReader : Interactables {

    public GameObject usableContainer;
    public GameObject idCard;
    


    public bool isCardUsed = false;
    public bool doorOpen = false;

    // Use this for initialization
    protected override void Start() {
        base.Start();

	}

    // Update is called once per frame
    protected override void Update () {
        if (Input.GetMouseButtonDown(0) && GlobalController.playerLookTarget != null) {
            if (_collider == GlobalController.playerLookTarget) {
                if (usableContainer.transform.childCount != 0 && idCard.transform != null) {
                    if (usableContainer.transform.GetChild(0) == idCard.transform) {
                        isCardUsed = true;
                        doorOpen = true;
                    }
                }
            }
        }
    }
}
