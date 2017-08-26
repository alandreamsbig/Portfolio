using UnityEngine;
using System;
using System.Collections;

public class HillSpawn : MonoBehaviour
{
  
    public GameObject HillPrefab;
    public GameObject RockPrefab;
    public GameObject RockPrefab2;
   // private float range = 10.0f;
	//private float hillLife = 5f;

    private Transform t;
    private Transform player;
    private float distance;

    private void Awake()
    {
        t = this.transform;
        player = GameObject.FindGameObjectWithTag("Player").transform;
    }

    private void Update()
    {
        if (player)
        {
            //Debug.Log(player.name + " is " + Distance().ToString() + " units from " + t.name);
            if (Distance() <= 20f)
            {
                transform.position = new Vector3((transform.position.x - 39.21f), (transform.position.y - 18.56f), transform.position.z);
                Instantiate(HillPrefab, transform.position, transform.rotation);
				//Destroy (HillPrefab, hillLife);

                Vector3 rockPos = new Vector3(UnityEngine.Random.Range(transform.position.x -14f, transform.position.x + 14f), transform.position.y + 8f, transform.position.z);
                Instantiate(RockPrefab, rockPos, transform.rotation);

                Vector3 rockPos2 = new Vector3(UnityEngine.Random.Range(transform.position.x - 14f, transform.position.x + 14f), transform.position.y + 8f, transform.position.z);
                Instantiate(RockPrefab2, rockPos2, transform.rotation);
            }
        }         

        else
            Debug.Log("Player not found!");


    }

    private float Distance()
    {
        
        return distance =  player.position.x - t.position.x;
    }
}
