using UnityEngine;
using System.Collections;

public class wasd : MonoBehaviour
{
	public float speed = 0.2f;
    public float boost = 0.25f;
	public float slow = 0.05f;
	private bool sandbox;

    //Movement Flags
    public bool isMoving;
    public bool isDiagonalUp;
    public bool isDiagonalDown;

    //For Animator
    public Animator animator;


    void Update()
	{
        //Checks whether the arrow keys are pressed or not.
        if (Input.GetKey("w") || Input.GetKey("a") || Input.GetKey("s") || Input.GetKey("d"))
            isMoving = true;
        else
            isMoving = false;

        //Checks for upward diagonal movement.
        if (Input.GetKey("w") && (Input.GetKey("a") || Input.GetKey("d")))
            isDiagonalUp = true;
        else
            isDiagonalUp = false;

        //Checks for downward diagonal movement.
        if (Input.GetKey("s") && (Input.GetKey("a") || Input.GetKey("d")))
            isDiagonalDown = true;
        else
            isDiagonalDown = false;

        animator.SetBool("moving", isMoving);
        animator.SetBool("diagonalUp", isDiagonalUp);
        animator.SetBool("diagonalDown", isDiagonalDown);


        if (sandbox) {
			Debug.Log ("pppppp");
			if (Input.GetKey ("w")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + slow);
                animator.SetTrigger("Back");

            }
			if (Input.GetKey ("a")) {
				transform.position = new Vector3 (transform.position.x - slow, transform.position.y, transform.position.z);
                animator.SetTrigger("Left");

            }
			if (Input.GetKey ("s")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - slow);
				animator.SetTrigger ("Front");
			}
			if (Input.GetKey ("d")) {
				transform.position = new Vector3 (transform.position.x + slow, transform.position.y, transform.position.z);
				animator.SetTrigger ("Right");
			}
		} else if (!sandbox) {

			if (Input.GetKey ("w")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + speed);
				animator.SetTrigger ("Back");
			}
			if (Input.GetKey ("a")) {
				transform.position = new Vector3 (transform.position.x - speed, transform.position.y, transform.position.z);
				animator.SetTrigger ("Left");
			}
			if (Input.GetKey ("s")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - speed);
				animator.SetTrigger ("Front");
			}
			if (Input.GetKey ("d")) {
				transform.position = new Vector3 (transform.position.x + speed, transform.position.y, transform.position.z);
				animator.SetTrigger ("Right");
			}


		} else if (gameObject.tag == "IT") {
			if (Input.GetKey ("w")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + boost);
				animator.SetTrigger ("Back");
			}
			if (Input.GetKey ("a")) {
				transform.position = new Vector3 (transform.position.x - boost, transform.position.y, transform.position.z);
				animator.SetTrigger ("Left");
			}
			if (Input.GetKey ("s")) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - boost);
				animator.SetTrigger ("Front");
			}
			if (Input.GetKey ("d")) {
				transform.position = new Vector3 (transform.position.x + boost, transform.position.y, transform.position.z);
				animator.SetTrigger ("Right");
			}
	
		}
	}



		void OnTriggerEnter(Collider col)
		{
			if (col.gameObject.tag == "sandbox") {
				sandbox = true;
				Debug.Log ("in sandbox");
			}
		}

		void OnTriggerExit(Collider c)
		{
			if (c.gameObject.tag == "sandbox") {
				sandbox = false;
				Debug.Log("exit sandbox");
			}
		}
	}