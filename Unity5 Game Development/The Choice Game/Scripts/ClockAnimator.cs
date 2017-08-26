using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class ClockAnimator : MonoBehaviour {

	public AudioClip tik;
	public AudioClip tok;
	AudioSource audio;

	private const float
	hoursToDegrees = 360f / 12f,
	minutesToDegrees = 360f / 60f,
	secondsToDegrees = 360f / 60f;

	public Transform hours, minutes, seconds;

	public bool analog;

	void Start(){

		audio = GetComponent<AudioSource> ();
	}

	void Update () {
		if (analog) {
			// currently do nothing
		}
		else {
			DateTime time = DateTime.Now;
			hours.localRotation = Quaternion.Euler(0f, 0f, time.Hour * hoursToDegrees);
			minutes.localRotation = Quaternion.Euler(0f, 0f, time.Minute * minutesToDegrees);
		    seconds.localRotation = Quaternion.Euler(0f, 0f, time.Second * secondsToDegrees);

			//audio.clip = tik;
			//audio.Play ();

			float degree = time.Second * secondsToDegrees;
			//Debug.Log (degree);
			if (degree == 24 || degree == 114 || degree == 234 && !audio.isPlaying) {
				playtok ();
			}
	
		}
	}

     void playtok(){
		audio.clip = tok;
		audio.Play ();
		//yield return new WaitWhile (() => audio.isPlaying);
	}
}
