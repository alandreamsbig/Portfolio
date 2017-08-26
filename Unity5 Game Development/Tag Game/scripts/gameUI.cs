using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gameUI : MonoBehaviour
{
    public GUIStyle guistyle = new GUIStyle();
    public GUIStyle outline = new GUIStyle(); //This will create a shadow cast text.
    public GameObject[] players;
    public GameObject winScreen;
    public Text winText;
    public bool isOver;

    //Overlay Screen
    public GUITexture overlay;

    void OnGUI()
    {
        if(players[0])
        {
            GUI.Label(new Rect(50, 15, 110, 110), "Player 1: " + players[0].GetComponent<newCounter>().currentTime, outline);
            GUI.Label(new Rect(50, 10, 100, 100), "Player 1: " + players[0].GetComponent<newCounter>().currentTime, guistyle);
        }
        if(players[1])
        {
            GUI.Label(new Rect(1000, 15, 110, 110), "Player 1: " + players[1].GetComponent<newCounter>().currentTime, outline);
            GUI.Label(new Rect(1000, 10, 100, 100), "Player 2: " + players[1].GetComponent<newCounter>().currentTime, guistyle);
        }
    }

    // Use this for initialization
    void Start ()
    {
        winText.text = " ";
        winScreen.SetActive(false);
        overlay = gameObject.GetComponent<GUITexture>();

        //Enables all scripts and movement at start of game.
        Time.timeScale = 1;
        players[0].GetComponent<newCounter>().enabled = true;
        players[0].GetComponent<arrowKey>().enabled = true;
        players[1].GetComponent<newCounter>().enabled = true;
        players[1].GetComponent<wasd>().enabled = true;
    }
	
	// Update is called once per frame
	void Update ()
    {
        //If the Player 1 is eliminated...
        if (!players[0] && players[1])
        {
            winText.text = "The Winner is Player 2!!!!";
            isOver = true;
            players[1].GetComponent<newCounter>().enabled = false;
            players[1].GetComponent<wasd>().enabled = false;
        }
            
        else if (!players[1] && players[0])
        {
            winText.text = "The Winneer is Player 1!!!!";
            isOver = true;
            players[0].GetComponent<newCounter>().enabled = false;
            players[0].GetComponent<arrowKey>().enabled = false;

        }

        if (isOver)
        {
            winScreen.SetActive(true);
            Time.timeScale = 0;
        }
    }
}
