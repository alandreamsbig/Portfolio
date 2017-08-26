using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Timer : MonoBehaviour {

	public float timeLeft = 60f;
	public Text text;
	public Text speed;
	public Text restart;

    public GameObject PlayerGameObj;

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		timeLeft -= Time.deltaTime;
		text.text = "Time: " + Mathf.Round (timeLeft);

		if (timeLeft < 0) {
			text.text = "Time: 0";

            HamsterSpeed SpeedScript = PlayerGameObj.GetComponent<HamsterSpeed>();


            speed.text = "Your fastest speed was: " + SpeedScript.TopSpeed;
			restart.text = "Press R to restart or Esc to the Menu";
			if (Input.GetKeyDown (KeyCode.Escape)) {
				SceneManager.LoadScene (0);
			} else if (Input.GetKeyDown ("r")) {
				SceneManager.LoadScene (1);
			}
		}
	}
}
