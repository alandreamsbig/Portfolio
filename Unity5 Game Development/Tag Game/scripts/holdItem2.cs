using UnityEngine;
using System.Collections;

public class holdItem2 : MonoBehaviour {


	public float speed = 500;
	public GameObject ball;
	public Transform guide;

	public float time = 4f;


	public int count = 0;

	public bool hasBall = false;
	public bool hasRope = false;
	public bool hasItem = false;
	public bool hasItem2;

	private GameObject ropee;
	private Collider collide;

	void Start(){
		ropee = GameObject.FindWithTag ("ropeCollide2");
		collide = ropee.GetComponent<BoxCollider> ();
		collide.enabled = false;
	}

	void Update()
	{
		//timeToFire -= Time.deltaTime;

		if(Input.GetKey("f"))//(timeToFire <= 0f))
		{
			if (hasBall == true && hasItem == true && hasItem2 == false) {
				GameObject projectile = (GameObject)Instantiate (ball, guide.position, Quaternion.Euler (90, 0, 0));
				//projectile.GetComponent<Rigidbody> ().AddForce (guide.forward* speed);
				//projectile.GetComponent<Rigidbody>().velocity =  new Vector3 (rb.velocity.x, rb.velocity.y, rb.velocity.z);
				projectile.GetComponent<Rigidbody> ().velocity = new Vector3 (10, 0, 0); //ball.transform.forward*
				Destroy (projectile, time);
				hasBall = false;
				hasItem = false;
			} else if (hasRope == true && hasItem2 == true && hasItem == false) {
				collide.enabled = true;
				Destroy (collide, time);
				hasRope = false;
				hasItem2 = false;
			}

		}

	}

	//use trigger or Collision
	void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "ball")
        {
            if(!hasItem)
            {
                Destroy(col.gameObject);
                hasBall = true;
                hasItem = true;
            }

		}
		else if (col.gameObject.tag == "rope")
        {
            if (!hasItem)
            {
                Destroy(col.gameObject);
                hasRope = true;
                hasItem = true;
            }

            /*Debug.Log ("omg");
				Destroy (col.gameObject);
				hasRope = true;
				hasItem2 = true;*/

		}


	}

}