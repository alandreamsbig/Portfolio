using UnityEngine;

public interface SignalRelay {
	void HandleSignal(int signal, SignalRelay sender);
	
	//Obsolete?
	int RequestValue(SignalRelay asker);

	GameObject GetGameObject();

	//void SendSignal(int signal);

	//void SetSender(SignalRelay sender);

}