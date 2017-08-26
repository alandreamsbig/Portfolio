using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class player2Counter : MonoBehaviour
{
	//public GameObject player1;
	public Text myText;
	public float elapsedTime; 
	private bool TimerOn;
	public GameObject player1;
//	public GameObject player2;

	// Use this for initialization
	void Start()
	{
		elapsedTime = 30f;

		myText.text = "Player 1: " + Mathf.Round (elapsedTime);

		TimerOn = false;

	}


	void Update()
	{

		if (TimerOn)
		{

			elapsedTime -= Time.deltaTime;
			myText.text = "Player 1: " + Mathf.Round (elapsedTime);
			//Debug.Log (elapsedTime);
			if (elapsedTime <= 0)
			{
				Destroy(player1);
				myText.text = "Time: " + "0";
			}
		}


	}
	void OnCollisionEnter(Collision col)
	{

		if (col.gameObject.tag == "player1") {
			

			TimerOn = false;
			player1.tag = "player1";
		
			//player2.tag = "player2";
			// Debug.Log("Not it!");
		} 

		else if (col.gameObject.tag == "IT") {
			elapsedTime = elapsedTime - 1f;
			TimerOn = true;
			player1.tag = "IT";
		

		}

	}


}