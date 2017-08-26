using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerSource : MonoBehaviour, SignalRelay {

	[SerializeField]
	public bool _isPowered;

	public void HandleSignal(int signal, SignalRelay sender) {
	}

	public int RequestValue(SignalRelay asker) {
		return _isPowered ? 1 : 0;
	}


	public GameObject GetGameObject() {
		return gameObject;
	}


}
