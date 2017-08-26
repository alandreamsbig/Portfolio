/*********************
 * Multiple Choice class
 * 
 * Description: Creates multiple choice questions and choices
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

import java.util.ArrayList;


public class MultipleChoice extends Question implements java.io.Serializable
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 2782911690330033045L;
	/**
	 * 
	 */
	
	private String questionType = "Multiple Choice";
	private ArrayList<String> Choices = new ArrayList<String>();
	
	public MultipleChoice() {
		
	}
	
	public MultipleChoice(String p)
	{
		this.setQuestionType(questionType);
		this.prompt = p;
	}

	public ArrayList<String> getChoices()
	{
		return Choices;
	}
	
	public void setChoices(ArrayList<String> c)
	{
		Choices = c;
	}
	
	public void addChoices(String addC)
	{
		Choices.add(addC);
	}
	
	public String getQuestionType()
	{
		return questionType;
	}

	@Override
	public void displayQuestion() {
		// TODO Auto-generated method sub
		o.send(prompt);
		for (int i=0; i < Choices.size(); i++)
		{
			System.out.println((i+1) + ") " + Choices.get(i));
		}
		
	}

	
	
	
	
	
}