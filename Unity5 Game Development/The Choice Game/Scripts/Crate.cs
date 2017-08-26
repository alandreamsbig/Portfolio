using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Crate : MonoBehaviour {

	public GameObject crateClosed;
	public GameObject crateOpen;


	private Vector3 crateClosedLocation, crateClosedScale;
	private Collider _crateCollider;
	
	private Animation _animation;

	// Use this for initialization
	void Start()
	{
		_crateCollider = GetComponent<BoxCollider>();
		_animation = GetComponent<Animation>();
	}

	// Update is called once per frame
	void Update()
	{
		if (Input.GetMouseButtonDown(0))
		{
			Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit))
			{
				if (hit.collider == _crateCollider)
				{

					if (_animation != null)
					{
						_animation.Play();
					}
				}
			}
		}
	}
}
