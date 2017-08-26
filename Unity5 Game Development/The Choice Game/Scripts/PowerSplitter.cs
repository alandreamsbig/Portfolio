using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerSplitter : MonoBehaviour, SignalRelay {

	public GameObject[] _recipients;
	private SignalRelay[] _recipientRelays;

	public GameObject GetGameObject() {
		return gameObject;
	}

	public void HandleSignal(int signal, SignalRelay sender) {
		foreach (SignalRelay r in _recipientRelays) {
			r.HandleSignal(signal, this);
		}
	}

	public int RequestValue(SignalRelay asker) {
		return 0;
	}
	
	void Start () {
		List<SignalRelay> recipientRelays = new List<SignalRelay>();
		foreach (GameObject g in _recipients) {
			recipientRelays.Add(g.GetComponent<SignalRelay>());
		}

		_recipientRelays = recipientRelays.ToArray();
	}
	
}
