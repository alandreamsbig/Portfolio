import java.io.Serializable;

import com.sun.speech.freetts.Voice;
import com.sun.speech.freetts.VoiceManager;

public class Audio implements Output,Serializable {
	

    /**
	 * 
	 */
	private static final long serialVersionUID = 359697163717354856L;

	public void send(String args) {
        
        String voiceName = "kevin16";
        
        VoiceManager voiceManager = VoiceManager.getInstance();
        Voice voice = voiceManager.getVoice(voiceName);

        voice.allocate();
        voice.speak(args);
        voice.deallocate();
    }
}