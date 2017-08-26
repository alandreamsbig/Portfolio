using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleSpawn : MonoBehaviour {

    [SerializeField]
    public GameObject HillPrefab;
    private float range = 10.0f;

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
            }
        }

        else
            Debug.Log("Player not found!");


    }

    private float Distance()
    {

        return distance = player.position.x - t.position.x;
    }
}
