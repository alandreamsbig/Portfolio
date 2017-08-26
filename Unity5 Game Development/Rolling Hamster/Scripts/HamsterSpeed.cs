using System.Collections;
using UnityEngine.UI;
using System.Collections.Generic;
using UnityEngine;

public class HamsterSpeed : MonoBehaviour {

    public Text SpeedText;
    public float TopSpeed = 0f;
    

    public Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }
    void FixedUpdate()
    {
        SpeedText.text = "Speed:" + Mathf.Round(rb.velocity.magnitude).ToString();

        if (Mathf.Round(rb.velocity.magnitude) > TopSpeed)
        {
            TopSpeed = Mathf.Round(rb.velocity.magnitude);
        }
    }
}
