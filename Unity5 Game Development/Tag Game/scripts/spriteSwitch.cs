using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class spriteSwitch : MonoBehaviour
{
    public Sprite[] sprites;

	// Use this for initialization
	void Start ()
    {
        gameObject.GetComponent<SpriteRenderer>().sprite = sprites[0];
	}
	
	// Update is called once per frame
	void Update ()
    {
		
	}

    void OnCollisionEnter(Collision col)
    {
        if(col.gameObject.tag == "Player" || col.gameObject.tag == "IT")
        {
            if (gameObject.GetComponent<SpriteRenderer>().sprite == sprites[0])
                gameObject.GetComponent<SpriteRenderer>().sprite = sprites[1];
            else
                gameObject.GetComponent<SpriteRenderer>().sprite = sprites[0];
        }

    }
}
