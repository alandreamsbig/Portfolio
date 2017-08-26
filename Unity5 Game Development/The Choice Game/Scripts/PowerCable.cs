using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerCable : MonoBehaviour, SignalRelay {
	[SerializeField]
	Material _matOn, _matOff;

	MeshRenderer _renderer;

	[SerializeField]
	public GameObject terminal1, terminal2;

	public SignalRelay relay1, relay2;

	public int relayState1, relayState2;

	// Use this for initialization
	void Start () {
		_renderer = GetComponent<MeshRenderer>();
		if (terminal1 != null)
			relay1 = terminal1.GetComponent<SignalRelay>();
		if (terminal2 != null)
			relay2 = terminal2.GetComponent<SignalRelay>();

		if (relay1 != null) {
			HandleSignal(relay1.RequestValue(this), relay1);
		}
		if (relay2 != null) {
			HandleSignal(relay2.RequestValue(this), relay2);
		}
	}

	// Update is called once per frame
	void Update () {
	}

	bool isHandlingSignal = false;

	public void HandleSignal(int signal, SignalRelay sender) {
		if (sender == relay1) {
			relayState1 = signal;
		} else if (sender == relay2) {
			relayState2 = signal;
		} else {
			return;
		}

		if (isHandlingSignal) {
			return;
		}

		isHandlingSignal = true;

		if (relayState1 > 0 || relayState2 > 0) {
			_renderer.material = _matOn;
		} else {
			_renderer.material = _matOff;
		}

		if (sender == relay2 && relay1 != null) {
			relay1.HandleSignal(signal, this);
		}
		if (sender == relay1 && relay2 != null) {
			relay2.HandleSignal(signal, this);
		}

		isHandlingSignal = false;

	}

	public int RequestValue(SignalRelay asker) {
		if (asker == relay1)
			if (relay2 != null) {
				return relayState2;
			}
		if (asker == relay2)
			if (relay1 != null) {
				return relayState1;
			}
		return 0;
	}

	public void SetSender(SignalRelay sender) {
		throw new NotImplementedException();
	}

	public GameObject GetGameObject()
	{
		return gameObject;
	}
}
