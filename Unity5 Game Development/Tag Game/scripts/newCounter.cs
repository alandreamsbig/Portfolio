using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class newCounter : MonoBehaviour
{
	//public GameObject player1;
    public Text myText;
	public float elapsedTime; 
    public bool TimerOn;
    public float currentTime;
	public float thrust;
	public Rigidbody rb;
    public bool isTagged;

    public GameObject ITindicator;


    // Use this for initialization
    void Start()
    {
		rb = GetComponent<Rigidbody> ();
	
		//myText.text = "Player 2: " + Mathf.Round (elapsedTime);

     	TimerOn = false;

    }


    void Update()
    {
        if (tag == "IT")
        {
            TimerOn = true;
            ITindicator.SetActive(true);
        }
        else
        {
            TimerOn = false;
            ITindicator.SetActive(false);
        }

        if(isTagged)
        {

        }


        if (TimerOn)
        {
			
			elapsedTime -= Time.deltaTime;
			//myText.text = "Player 2: " + Mathf.Round (elapsedTime);
			//Debug.Log (elapsedTime);
            if (elapsedTime <= 0)
            {
				Destroy(this.gameObject);
				myText.text = "Player 2: " + "0";
            }
        }
        currentTime = Mathf.Round(elapsedTime * 10) / 10;
	

    }
	void OnCollisionEnter(Collision col)
	{
		if (col.gameObject.tag == "Player")
        {
            //elapsedTime = elapsedTime - 1f;
			Debug.Log("haha");
            TimerOn = true;
            col.gameObject.tag = "IT";

            // Debug.Log("Not it!");
        }

		else if (col.gameObject.tag == "IT")
        {
            TimerOn = false;
            col.gameObject.tag = "Player";
            //rb.AddForce (this.gameObject.transform.position * thrust);
        }
    }

    /*void OnGUI()
    {
        if(gameObject.tag == "player1")
        {
            GUI.Label(new Rect(15, 10, 100, 100), "Player 1: " + Mathf.Round(elapsedTime), guistyle);
        }
        if(gameObject.tag == "player2")
            GUI.Label(new Rect(50, 10, 100, 100), "Player 2: " + Mathf.Round(elapsedTime), guistyle);
    }*/


}
