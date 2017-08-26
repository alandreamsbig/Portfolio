using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class counter : MonoBehaviour
{
	//public GameObject player1;
    public Text myText;
	public float elapsedTime; 
    public bool TimerOn;
//	public GameObject player1;
	public GameObject player2;
    public GameObject ITindicator;

    private GUIStyle guistyle = new GUIStyle();

    // Use this for initialization
    void Start()
    {
		elapsedTime = 30f;
	
		myText.text = "Player 2: " + Mathf.Round (elapsedTime);

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


        if (TimerOn)
        {
			
			elapsedTime -= Time.deltaTime;
			myText.text = "Player 2: " + Mathf.Round (elapsedTime);
			//Debug.Log (elapsedTime);
            if (elapsedTime <= 0)
            {
				Destroy(player2);
				myText.text = "Player 2: " + "0";
            }
        }
	

    }
	void OnCollisionEnter(Collision col)
	{
      
        if (col.gameObject.tag == "player2")
        {
			elapsedTime = elapsedTime - 1f;
	
			TimerOn = true;
			player2.tag = "IT";
		
			// Debug.Log("Not it!");
		} 

		else if (col.gameObject.tag == "IT") {
			TimerOn = false;
			player2.tag = "player2";
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
