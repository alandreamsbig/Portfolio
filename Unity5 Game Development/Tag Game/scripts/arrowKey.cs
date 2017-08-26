using UnityEngine;
using System.Collections;

public class arrowKey: MonoBehaviour
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
    //animator.SetFloat(currentSpeed);
	void Update()
	{
        //Checks whether the arrow keys are pressed or not.
        if (Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.LeftArrow) || Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.RightArrow))
            isMoving = true;
        else
            isMoving = false;

        //Checks for upward diagonal movement.
        if (Input.GetKey(KeyCode.UpArrow) && (Input.GetKey(KeyCode.LeftArrow) || Input.GetKey(KeyCode.RightArrow)))
            isDiagonalUp = true;
        else
            isDiagonalUp = false;

        //Checks for downward diagonal movement.
        if (Input.GetKey(KeyCode.DownArrow) && (Input.GetKey(KeyCode.LeftArrow) || Input.GetKey(KeyCode.RightArrow)))
            isDiagonalDown = true;
        else
            isDiagonalDown = false;

        animator.SetBool("moving", isMoving);
        animator.SetBool("diagonalUp", isDiagonalUp);
        animator.SetBool("diagonalDown", isDiagonalDown);

 
		if (sandbox){
			Debug.Log ("pppppp");
			if (Input.GetKey (KeyCode.UpArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + slow);
                animator.SetTrigger("Back");
            }
			if (Input.GetKey (KeyCode.LeftArrow)) {
				transform.position = new Vector3 (transform.position.x - slow, transform.position.y, transform.position.z);
                animator.SetTrigger("Left");
            }
			if (Input.GetKey (KeyCode.DownArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - slow);
                animator.SetTrigger("Front");
            }
			if (Input.GetKey (KeyCode.RightArrow)) {
				transform.position = new Vector3 (transform.position.x + slow, transform.position.y, transform.position.z);
                animator.SetTrigger("Right");
            }
		}

		else if (!sandbox){

			if (Input.GetKey (KeyCode.UpArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + speed);
                animator.SetTrigger("Back");
            }
			if (Input.GetKey (KeyCode.LeftArrow)) {
				transform.position = new Vector3 (transform.position.x - speed, transform.position.y, transform.position.z);
                animator.SetTrigger("Left");
            }
			if (Input.GetKey (KeyCode.DownArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - speed);
                animator.SetTrigger("Front");
            }
			if (Input.GetKey (KeyCode.RightArrow)) {
				transform.position = new Vector3 (transform.position.x + speed, transform.position.y, transform.position.z);
                animator.SetTrigger("Right");
            }


		}
		else if (gameObject.tag == "IT") {
			if (Input.GetKey (KeyCode.UpArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z + boost);
				animator.SetTrigger("Back");
			}
			if (Input.GetKey (KeyCode.LeftArrow)) {
				transform.position = new Vector3 (transform.position.x - boost, transform.position.y, transform.position.z);
				animator.SetTrigger("Left");
			}
			if (Input.GetKey (KeyCode.DownArrow)) {
				transform.position = new Vector3 (transform.position.x, transform.position.y, transform.position.z - boost);
				animator.SetTrigger("Front");
			}
			if (Input.GetKey (KeyCode.RightArrow)) {
				transform.position = new Vector3 (transform.position.x + boost, transform.position.y, transform.position.z);
				animator.SetTrigger("Right");
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