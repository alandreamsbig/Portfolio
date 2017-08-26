using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

	public CameraController _camera;

	private Rigidbody _playerBody;

	[SerializeField]
	private float playerSpeed;
	
	// Use this for initialization
	void Start () {
		_playerBody = GetComponent<Rigidbody>();
		GlobalController.player = this;
	}
	
	// Update is called once per frame
	void Update () {
		float xMove = 0f, zMove = 0f;
		if (Input.GetKey(KeyCode.A)) {
			xMove -= 1f;
		}
		if (Input.GetKey(KeyCode.D)) {
			xMove += 1f;
		}
		if (Input.GetKey(KeyCode.S)) {
			zMove -= 1f;
		}
		if (Input.GetKey(KeyCode.W)) {
			zMove += 1f;
		}

		if (_camera._lookState == CameraController.LookState.FreeLook)
			_playerBody.AddForce(Quaternion.Euler(0, _camera.playerYaw, 0) * new Vector3(xMove, 0, zMove).normalized * playerSpeed, ForceMode.Force);
		//_playerBody.AddForce(_playerBody. Quaternion.Euler(0, _camera.playerYaw, 0) * new Vector3(xMove, 0, zMove).normalized, ForceMode.Force);

	}
}
