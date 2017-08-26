using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IdCard : MonoBehaviour {

	[SerializeField]
	private CardReader _cardReader;
	[SerializeField]
	private Transform _cardReaderTransform;
	
	// Update is called once per frame
	void Update () {
		if (_cardReader != null && _cardReader.isCardUsed) {
			//this.gameObject.SetActive(false);
			this.transform.SetParent(_cardReaderTransform);
			this.transform.localPosition = _cardReaderTransform.localPosition;
			this.transform.localRotation = _cardReaderTransform.localRotation;
		}
	}
}
