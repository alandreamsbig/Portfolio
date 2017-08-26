/*********************
 * Question class
 * 
 * Description: Handles all the question types including T/F, Multiple Choice, Essay, Short answer, Matching and ranking.
 * 				Saves the prompt depending on the question type.
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

import java.io.Serializable;

public abstract class Question implements Serializable
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	protected String prompt;
	protected String ans;
	private String questionType = null;
	private int minAnswer = 1;
	private String response;
	
	public static Audio o = new Audio();
	
	public Question()
	{
		
	}
	
	public String getQuestion()
	{
		return prompt;
	}
	
	public void setQuestion(String q)
	{
		prompt = q;
	}
	
	public String getAnswer()
	{
		return ans;
	}
	
	public void setAnswer(String a)
	{
		ans = a;
	}
	
	public String getResponse()
	{
		return response;
	}
	
	public void setResponse(String r)
	{
		response = r;
	}
	
	public String getQuestionType()
	{
		return questionType;
	}
	
	public void setQuestionType(String qt)
	{
		this.questionType = qt;
	}
	
	public void setMinAnswer(int i)
	{
		minAnswer = i;
	}
	
	public int getMinAnser()
	{
		return minAnswer;
	}
	
	//Display questions
	abstract void displayQuestion();
	
	
}