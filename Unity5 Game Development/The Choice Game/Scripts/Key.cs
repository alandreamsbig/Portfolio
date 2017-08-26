using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Key : MonoBehaviour {

    public Painting painting;
    public Transform keyhole;
	
	// Update is called once per frame
	void Update () {
		if(painting.isKeyUsed) {
            //this.gameObject.SetActive(false);
            this.transform.SetParent(painting.transform);
            this.transform.localPosition = keyhole.localPosition;
            this.transform.localRotation = keyhole.localRotation;
        }
	}
}
