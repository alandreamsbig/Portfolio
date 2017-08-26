using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class menuControls : MonoBehaviour
{

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void restartLevel()
    {
        Application.LoadLevel(Application.loadedLevel);
    }

    public void returnToTitle()
    {
        Application.LoadLevel(0);
    }

    public void quitGame()
    {
        Application.Quit();
    }
}
