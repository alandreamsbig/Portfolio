/*********************
 * Ranking class
 * 
 * Description: Creates ranking class question 
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

import java.util.ArrayList;

public class Ranking extends Matching
{
	private ArrayList<String> Choices = new ArrayList<String>();
	/**
	 * 
	 */
	private static final long serialVersionUID = -3182187514179010875L;
	private String questionType = "Ranking";
	
	public Ranking(String p)
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
		// TODO Auto-generated method stub
		o.send(prompt);
		for (int i=0; i < Choices.size(); i++)
		{
			System.out.println((i+1) + ") " + Choices.get(i));
		}
	}
	
}