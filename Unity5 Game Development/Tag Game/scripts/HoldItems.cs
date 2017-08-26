using UnityEngine;
using System.Collections;

public class HoldItems : MonoBehaviour {


	public float speed = 500;
	public GameObject ball;
	public Transform guide;

	public float time = 4f;


	public int count = 0;

    public bool hasBall;
	public bool hasRope;
	private GameObject ropee;
	private Collider collide;

	void Start(){
		ropee = GameObject.FindWithTag ("ropeCollide");
		collide = ropee.GetComponent<BoxCollider> ();
		collide.enabled = false;
	}

	void Update()
	{
		//timeToFire -= Time.deltaTime;

		if(Input.GetKey(KeyCode.RightShift) && hasBall)//(timeToFire <= 0f))
		{
			
			GameObject projectile = (GameObject)Instantiate (ball, guide.position, Quaternion.Euler(90, 0, 0));
            //projectile.GetComponent<Rigidbody> ().AddForce (guide.forward* speed);
            //projectile.GetComponent<Rigidbody>().velocity =  new Vector3 (rb.velocity.x, rb.velocity.y, rb.velocity.z);
			projectile.GetComponent<Rigidbody>().velocity =  new Vector3(10,0,0); //ball.transform.forward*
            Destroy (projectile, time);
            hasBall = false;
		
		}
		else if(Input.GetKey(KeyCode.RightShift) && hasRope)
		{
				collide.enabled = true;
				Destroy (collide, time);
				hasRope = false;

		}

	}

	//use trigger or Collision
	void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "ball") {
            Destroy(col.gameObject);
            //count = 1;
            hasBall = true;
		
		}
		else if (col.gameObject.tag == "rope") {
			Debug.Log ("omg");
			Destroy(col.gameObject);
			hasRope = true;

		}
	

	}

}