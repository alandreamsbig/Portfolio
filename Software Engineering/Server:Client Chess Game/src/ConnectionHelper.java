import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class ConnectionHelper {
static Socket socket_;
ObjectOutputStream outps ;
ObjectInputStream inpus ;
public void connect(){
	 try {
		socket_ = new Socket("10.250.111.162", 1900);
		outps= new ObjectOutputStream(socket_.getOutputStream());
		inpus= new ObjectInputStream(socket_.getInputStream());
	} catch (UnknownHostException e) {
		System.out.println("Connection error");
	} catch (IOException e) {
		System.out.println("Connection error");
		e.printStackTrace();
	}
	
	
	
}
public String ReadPlayer(){
	
	try {
	
	
		String pid=(String)inpus.readObject();
		return pid;
	} catch (ClassNotFoundException | IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	return "error";
}


public Move Read(){
	try {
		
		Move mv=(Move)inpus.readObject();
		return mv;
	} catch (IOException | ClassNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	return null;

}
public void closeConnection(){
	try {
		
		Move close=null;
		outps.writeObject(close);
		socket_.close();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	
	
	
}
public void Write(Move mv) {
	try {
		outps.reset();
		outps.writeObject(mv);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
}



}
