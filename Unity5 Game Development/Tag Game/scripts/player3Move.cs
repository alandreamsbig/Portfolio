using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player3Move : MonoBehaviour {

	public float speed = 0.2f;
	public float boost = 0.25f;

	void Update()
	{
		if (gameObject.tag == "IT")
		{
			if (Input.GetKey("y"))
			{
				transform.position = new Vector3(transform.position.x, transform.position.y, transform.position.z + boost);
			}
			if (Input.GetKey("g"))
			{
				transform.position = new Vector3(transform.position.x - boost, transform.position.y, transform.position.z);
			}
			if (Input.GetKey("h"))
			{
				transform.position = new Vector3(transform.position.x, transform.position.y, transform.position.z - boost);
			}
			if (Input.GetKey("j"))
			{
				transform.position = new Vector3(transform.position.x + boost, transform.position.y, transform.position.z);
			}
		}
		else
		{
			if (Input.GetKey("y"))
			{
				transform.position = new Vector3(transform.position.x, transform.position.y, transform.position.z + speed);
			}
			if (Input.GetKey("g"))
			{
				transform.position = new Vector3(transform.position.x - speed, transform.position.y, transform.position.z);
			}
			if (Input.GetKey("h"))
			{
				transform.position = new Vector3(transform.position.x, transform.position.y, transform.position.z - speed);
			}
			if (Input.GetKey("j"))
			{
				transform.position = new Vector3(transform.position.x + speed, transform.position.y, transform.position.z);
			}
		}
	}
}
