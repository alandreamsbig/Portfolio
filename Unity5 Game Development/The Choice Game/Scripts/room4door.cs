using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class room4door : MonoBehaviour {

    public CardReader cardReader;
	private Animator _animate;


	void Start(){
		_animate = GetComponent<Animator> ();
	}

	// Update is called once per frame
	void Update () {
		if(cardReader.doorOpen) {
            //this.gameObject.SetActive(false);
           // Debug.Log("Final Open");
            _animate.SetTrigger("FinalOpen");
        }
    }
}
