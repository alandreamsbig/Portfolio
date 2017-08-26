using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class Safe : MonoBehaviour {

	public GameObject safeClosed;
	public GameObject safeOpen;

	public Button[] numbers;
	public Button enter;

	public Text rightOrWrong;

	private string code;

	private Vector3 safeClosedLocation, safeClosedScale;

	// Use this for initialization
	void Start () {
		if (safeClosed != null)
		{
			safeClosedLocation = safeClosed.transform.position;
			safeClosedScale = safeClosed.transform.localScale;
		}
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown(0))
		{
			Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit))
			{
				if(hit.transform.name == "Greybox_SafeClosed")
				{
					foreach(Button b in numbers)
					{
						b.gameObject.SetActive(true);
					}
					enter.gameObject.SetActive(true);
				}
			}
		}

		if(Input.GetKeyDown(KeyCode.Escape))
		{
			if (numbers != null)
			{
				foreach (Button b in numbers)
				{
					b.gameObject.SetActive(false);
				}
				enter.gameObject.SetActive(false);
				rightOrWrong.gameObject.SetActive(false);
			}
		}
	}

	public void NumberPressed()
	{
		string number = EventSystem.current.currentSelectedGameObject.name;
		code += number;
	}

	public void EnterPressed()
	{
		if(code == "2582")
		{
			rightOrWrong.text = "Correct";
			code = null;
			GameObject safe = Instantiate(safeOpen);
			safe.AddComponent<Safe>();
			safe.transform.localPosition = safeClosedLocation;
			safe.transform.localScale = safeClosedScale;
			Destroy(safeClosed);
		}
		else
		{
			rightOrWrong.text = "Wrong";
			code = null;
		}
		rightOrWrong.gameObject.SetActive(true);
	}
}
