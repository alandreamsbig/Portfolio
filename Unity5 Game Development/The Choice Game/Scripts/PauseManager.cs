using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PauseManager : MonoBehaviour {

    [SerializeField]
    private Image _pauseScreen;
    [SerializeField]
    private Button _resumeButton;
    [SerializeField]
    private Button _mainMenuButton;
    [SerializeField]
    private Button _exitButton;

    private bool isPaused = false;

    void Start() {
        _pauseScreen.gameObject.SetActive(false);
        _resumeButton.gameObject.SetActive(false);
        _mainMenuButton.gameObject.SetActive(false);
        _exitButton.gameObject.SetActive(false);
    }

	// Update is called once per frame
	void Update () {
		if(Input.GetKeyDown(KeyCode.P)) {
            if(!isPaused) {
                Pause();
            }
            else {
                Resume();
            }
        }
	}

    public void ResumeButton() {
        Resume();
    }

    public void MainMenuButton() {
        SceneManager.LoadScene(0);
    }

    public void ExitButton() {
        Application.Quit();
    }

    private void Pause() {
        _pauseScreen.gameObject.SetActive(true);
        _resumeButton.gameObject.SetActive(true);
        _mainMenuButton.gameObject.SetActive(true);
        _exitButton.gameObject.SetActive(true);
        Time.timeScale = 0;
        GlobalController.player._camera._lookState = CameraController.LookState.Paused;
        isPaused = true;
    }

    private void Resume() {
        _pauseScreen.gameObject.SetActive(false);
        _resumeButton.gameObject.SetActive(false);
        _mainMenuButton.gameObject.SetActive(false);
        _exitButton.gameObject.SetActive(false);
        Time.timeScale = 1;
        GlobalController.player._camera._lookState = CameraController.LookState.FreeLook;
        isPaused = !isPaused;
    }
}
