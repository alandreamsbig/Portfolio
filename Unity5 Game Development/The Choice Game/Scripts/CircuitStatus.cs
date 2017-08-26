using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CircuitStatus : MonoBehaviour, SignalRelay {

    [SerializeField]
    private GameObject _yellowPanel;
    [SerializeField]
    private GameObject _greenPanel;

    public void HandleSignal(int signal, SignalRelay sender) {
        if (signal > 0) {
            _yellowPanel.GetComponent<Renderer>().material.DisableKeyword("_EMISSION");
            _greenPanel.GetComponent<Renderer>().material.EnableKeyword("_EMISSION");
        }
        else {
            _yellowPanel.GetComponent<Renderer>().material.EnableKeyword("_EMISSION");
            _greenPanel.GetComponent<Renderer>().material.DisableKeyword("_EMISSION");
        }
    }

    public GameObject GetGameObject() {
        return gameObject;
    }

    public int RequestValue(SignalRelay asker) {
        return 0;
    }

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
