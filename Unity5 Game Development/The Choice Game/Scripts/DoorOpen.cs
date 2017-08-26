using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DoorOpen : MonoBehaviour {

    public Keypad keypadScript;
	private Animator _animate;
	private bool open;

	// Use this for initialization
	void Start () {
        //GameObject door = GameObject.
        //keypadScript = keypad.GetComponent<Keypad>();
		_animate = GetComponent<Animator> ();
		open = false;
    }
	
	// Update is called once per frame
	void Update () {
		if(keypadScript.isCorrect) {
            
            keypadScript.isCorrect = false;
			//this.gameObject.SetActive(false);

			if (!open) {
				open = true;
				_animate.SetTrigger ("Door1Open");
				Debug.Log ("Door Open");
			}

			if (_animate.GetCurrentAnimatorStateInfo(0).IsName("Door1Open"))
			{
				gameObject.active = false;
			}
        }
	}

	private IEnumerator WaitForAnimation ( Animation animation )
	{
		do
		{
			yield return null;
		} while ( animation.isPlaying );
	}

}
