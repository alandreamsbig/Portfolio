using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HamsterJump : MonoBehaviour {

    public bool isFalling = true;
    public Rigidbody rb;

    public float bounce = 500f;
    public Vector3 GroundPos;

    // Use this for initialization
    void Start () {

        rb = GetComponent<Rigidbody>();

    }
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown("space") && !isFalling){

           rb.AddForce(new Vector3(2f, bounce, 0f));
       
            isFalling = true;

        }

        

    }

    void OnCollisionEnter(Collision collision)
    {
        isFalling = false;
        ContactPoint contact = collision.contacts[0];
        GroundPos = contact.point;
    }
}
