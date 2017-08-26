using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LampToggle : MonoBehaviour, SignalRelay {

	private const string EmissionColor = "_EmissionColor";

	public Camera mainCamera;
	private Light _lamp;
	public float _lampshadeEmission;
	public Color _lampshadeEmissionColor;


	[SerializeField]
	public MeshRenderer _lampshade;
	
	public GameObject GetGameObject() {
		return gameObject;
	}

	public void HandleSignal(int signal, SignalRelay sender) {
		if (signal > 0) {
			if (_lamp != null) {
				_lamp.enabled = true;
			}
			if (_lampshade != null)
			{
				DynamicGI.SetEmissive(_lampshade, _lampshadeEmissionColor * 1f);
				_lampshade.material.EnableKeyword("_EMISSION");
				_lampshade.material.globalIlluminationFlags = MaterialGlobalIlluminationFlags.RealtimeEmissive;
				//_lampshade.material.SetFloat(Emissive, _lampshadeEmission);
			}
		}
		else {
			if(_lamp != null) {
				_lamp.enabled = false;
			}
			if (_lampshade != null) {
				DynamicGI.SetEmissive(_lampshade, _lampshadeEmissionColor * 0f);
				_lampshade.material.DisableKeyword("_EMISSION");
				_lampshade.material.globalIlluminationFlags = MaterialGlobalIlluminationFlags.EmissiveIsBlack;
				//_lampshade.material.SetFloat(Emissive, 0f);
			}
		}
	}

	public int RequestValue(SignalRelay asker) {
		return 0;
	}

	// Use this for initialization
	void Start () {
		_lamp = GetComponentInChildren<Light>();
		if (_lampshade != null) {
			_lampshade.material.globalIlluminationFlags = MaterialGlobalIlluminationFlags.RealtimeEmissive;
			_lampshadeEmissionColor = _lampshade.material.GetColor("_EmissionColor");
			//_lampshade.material.SetFloat(Emission, 0f);
			DynamicGI.SetEmissive(_lampshade, _lampshadeEmissionColor * 0f);
			//_lampshade.renderer.
			//Debug.Log(_lamp.name);
		}
	}

	// Update is called once per frame
	void Update() {
		//if (Input.GetMouseButtonDown(0)) {

		//	Ray rays = mainCamera.ScreenPointToRay(Input.mousePosition);
		//	RaycastHit hit;
		//	if (Physics.Raycast(rays, out hit)) {
		//		if (hit.transform.name == this.name)
		//		{
		//			_lamp.enabled = true;
		//		}
		//	}
		//}
	}
}
