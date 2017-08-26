using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ButtonManager : MonoBehaviour {

    public void StartClicked() {
        SceneManager.LoadScene(1);
    }

    public void ExitButton() {
        Application.Quit();
    }

    public void CreditsButton() {
        SceneManager.LoadScene(2);
    }

}
