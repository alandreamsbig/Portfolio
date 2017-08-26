using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Space : MonoBehaviour {

    private Transform player;
    private Transform spawn;
    private float distance;
    private float alpha;

    private float StartNum;
    private float percent;

    public GameObject PlayerGameObj;
    public float SpaceStart = 10f;
    public float SpaceComplete = 30f;
    public float fadeTime = 1f;

    public SpriteRenderer ThisColor;
    

    private void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        spawn = GameObject.FindGameObjectWithTag("Spawn").transform;
    }

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        Debug.Log(player.name + " is " + Distance().ToString() + " units from " + spawn.name);   

        if (Distance() > SpaceStart)
        {
            StartNum = Distance() - SpaceStart;
            percent = StartNum / SpaceComplete;
            alpha = 1f * percent;

            Color color = ThisColor.color;
            Color newColor = new Color(1, 1, 1, alpha);
            ThisColor.color = newColor;

            //Debug.Log(GetComponent<SpriteRenderer>().color.a);
            
        }

        if (Distance() < SpaceStart)
        {
            StartCoroutine(FadeTo(0, fadeTime));
        }

        

    }

    private float Distance()
    {
        HamsterJump JumpScript = PlayerGameObj.GetComponent<HamsterJump>();
        return distance = player.position.y - JumpScript.GroundPos.y;
       
    }

    IEnumerator FadeTo(float aValue, float aTime)
    {
        
        Color color = ThisColor.color;
        float alpha = color.a;
        for (float t = 0.0f; t < 1.0f; t += Time.deltaTime / aTime)
        {
            Color newColor = new Color(1, 1, 1, Mathf.Lerp(alpha, aValue, t));
            ThisColor.color = newColor;

            Debug.Log(newColor + "equals" + ThisColor.color);
            yield return null;
        }
    }
    }
