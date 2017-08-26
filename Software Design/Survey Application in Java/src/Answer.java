/*********************
 * Answer class
 * 
 * Description: Creates answers for test
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */


import java.io.Serializable;
import java.util.ArrayList;


public class Answer implements Serializable
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 8989526767460028412L;
	private ArrayList<String> answer = new ArrayList<String>();
	
	public Answer()
	{
		
	}
	
	public ArrayList<String> getAnswer()
	{
		return answer;
	}
	
	public void setAnswer(ArrayList<String> a)
	{
		answer = a;
	}
	
	public void addAnswer(String addC)
	{
		answer.add(addC);
	}
}