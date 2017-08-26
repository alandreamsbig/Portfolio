using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EmergencyLight : MonoBehaviour, SignalRelay {

	Light _light;
	float lightBrightness;
	float lightMultiplier;

	bool isOn;
	float timeSinceOn;

	void Start () {
		_light = GetComponent<Light>();
		isOn = true;
		timeSinceOn = 0f;
		lightBrightness = 0f;
	}
	
	void Update () {
		//if (isOn) {
		//	timeSinceOn += Time.deltaTime;
		//} else {
		//	timeSinceOn -= Time.deltaTime;
		//}
		//if (timeSinceOn < 0f)
		//	timeSinceOn = 0f;
		timeSinceOn += Time.deltaTime;

		lightMultiplier = 1f - Mathf.Exp(10f * -timeSinceOn);

		if (isOn) {
			lightBrightness = Mathf.Sin(timeSinceOn);
			lightBrightness = 10f * lightBrightness * lightBrightness;
			lightMultiplier = 1f;
		}


		if (isOn)
			_light.intensity = Mathf.Lerp(0, lightBrightness, lightMultiplier);
		else
			_light.intensity = Mathf.Lerp(lightBrightness, 0, lightMultiplier);


	}

	public GameObject GetGameObject() {
		return gameObject;
	}
	
	public void HandleSignal(int signal, SignalRelay sender) {
		if (signal > 0 && isOn) {
			isOn = false;
			timeSinceOn = 0f;
		}
		if (signal == 0 && !isOn) {
			isOn = true;
			timeSinceOn = 0f;
		}
	}
	
	public int RequestValue(SignalRelay asker) {
		return 0;
	}
}

