using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerDial : Interactables, SignalRelay {

	[SerializeField]
	public Material litMat;

	float remainingAngleOffset = 0f;

	[SerializeField]
	bool[] _angleBridges = new bool[8];
	[SerializeField]
	bool[] _straightBridges = new bool[4];

	// 128,	64,  32,	16,   8,	 4,   2,	 1
	// N-E, NE-SE, E-S, SE-SW, S-W, SW-NW, N-W, NE-NW, -WRONB
	//						 N-S, NE-SW, E-W, SE-NW, -WRONG
	[SerializeField]
	private byte angleBridgeMap;
	[SerializeField]
	private byte straightBridgeMap;

	// N, E, S, W
	[SerializeField]
	public GameObject[] cables = new GameObject[4];

	public SignalRelay[] terminals = new SignalRelay[4];
	public int[] cableStates = new int[4];
	protected override void Start() {
		base.Start();

		for (int i = 0; i < 4; i++) {
			if (cables[i] != null) {
				terminals[i] = cables[i].GetComponent<SignalRelay>();
			}
		}
		refreshTerminals();

		for (int i = 0; i < 8; i++) {
			if (_angleBridges[i]) {
				angleBridgeMap += (byte)(1 << i);
			}
		}


		for (int i = 0; i < 4; i++) {
			if (_straightBridges[i]) {
				straightBridgeMap += (byte)(1 << i);
			}
		}
	}

	protected override void OnInteract(bool rightClick = false) {
		if (rightClick)
			return;


		if (angleBridgeMap >= 128) {
			angleBridgeMap -= 128;
			angleBridgeMap <<= 1;
			angleBridgeMap++;
		} else {
			angleBridgeMap <<= 1;
		}
		if (straightBridgeMap >= 8) {
			straightBridgeMap %= 8;
			straightBridgeMap <<= 1;
			straightBridgeMap++;
		} else {
			straightBridgeMap %= 8;
			straightBridgeMap <<= 1;
		}
		//refreshTerminals();

		remainingAngleOffset -= 45f;

		//	128	64	32	16	8	4	2	1
		//0	  E  -   -   -  -   -   W   -
		//1   N  -   S   -  -   -   -   -
		//2   -  -   E   -  W   -   -   -
		//3   -  -   -   -  S   -   N   -

		//	 8 4 2 1
		//0	 S - - -
		//1  - - W -
		//2  - - E -
		//3  N - - -

		// 128,	64,  32,	16,   8,	 4,   2,	 1
		// N-E, NE-SE, E-S, SE-SW, S-W, SW-NW, N-W, NE-NW, -
		//						 N-S, NE-SW, E-W, SE-NW, -
		for (int i = 0; i < 4; i++) {
			if (terminals[i] == null)
				continue;
			int partner = GetPartner(i*2);
			if (partner >= 0) {
				terminals[i].HandleSignal(cableStates[partner], this);
			} else {
				terminals[i].HandleSignal(0, this);
			}
		}
	}

	public void HandleSignal(int signal, SignalRelay sender) {
		for (int i = 0; i < 4; i++) {
			if (sender == terminals[i]) {
				cableStates[i] = signal;
				
				int partner = GetPartner(i*2);
				if (partner >= 0 && terminals[partner] != null) {
					terminals[partner].HandleSignal(signal, this);
				}
			}
		}
	}

	public int RequestValue(SignalRelay asker) {
		return 0;
	}

	private void refreshTerminals() {
		for (int i = 0; i < 4; i++) {
			if (terminals[i] != null)
				cableStates[i] = terminals[i].RequestValue(this);
		}

	}


	//45*i = angle clockwise
	private int GetPartner(int input) {
		int straightBit = input % 4;
		byte map = (byte)(1 << straightBit);
		byte andedmap = (byte)(straightBridgeMap & map);
		if (andedmap != 0) {
			return ((input + 4) % 8) / 2;
		}

		if ((angleBridgeMap & (1 << (input % 8))) != 0) {
			return ((input + 2) % 8) / 2;
		}

		if ((angleBridgeMap & (1 << ((input + 6) % 8))) != 0) {
			return ((input + 6) % 8) / 2;
		}

		return -1;
	}

	protected override void Update() {
		base.Update();
		transform.Rotate(new Vector3(0f, 0f, remainingAngleOffset / 4f), Space.Self);
		remainingAngleOffset *= 3f /4f;

	}

	public GameObject GetGameObject()
	{
		return gameObject;
	}
}


