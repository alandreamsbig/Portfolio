/*********************
 * Matching class
 * 
 * Description: Creates matching question
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

import java.util.ArrayList;

public class Matching extends Question implements java.io.Serializable
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 7079511304564858542L;
	private String questionType = "Matching";
	private ArrayList<String> leftChoices = new ArrayList<String>();
	private ArrayList<String> rightChoices = new ArrayList<String>();
	private ArrayList<String> MatchingChoices = new ArrayList<String>();
	
	public Matching(){
		
	}
	
	public Matching(String p)
	{
		this.setQuestionType(questionType);
		this.prompt = p;
	}
	
	public void addLeft(String e)
	{
		leftChoices.add(e);
	}
	
	public void addRight(String d)
	{
		rightChoices.add(d);
	}
	
	public void addMatchingChoices(String mc)
	{
		MatchingChoices.add(mc);
	}
	
	public ArrayList<String> getLeft()
	{
		return leftChoices;
	}
	
	public ArrayList<String> getRight()
	{
		return rightChoices;
	}
	
	public ArrayList<String> getMC()
	{
		return MatchingChoices;
	}
	
	public void setLeft(ArrayList<String> leftChoices)
	{
		this.leftChoices = leftChoices;
	}
	
	public void setRight(ArrayList<String> rightChoices)
	{
		this.rightChoices = rightChoices;
	}
	
	public void setMatchingChoices(ArrayList<String> MatchingChoices)
	{
		this.MatchingChoices = MatchingChoices;
	}
	
	public void checkMatches()
	{
		//takes user input, check with the answer and see if they match
	}
	
	public String getQuestion()
	{
		return questionType;
	}

	@Override
	public void displayQuestion() {
		// TODO Auto-generated method stub
		o.send(prompt);
		for (int i=0; i < leftChoices.size(); i++)
		{
			System.out.println((i+1) + ") " + leftChoices.get(i) + "   " + (i+1) + ") " + rightChoices.get(i));
		}
		
		/*for (int k=0; k < rightChoices.size(); k++)
		{
			System.out.println(k+1 + ") " + rightChoices.get(k));
		}
		*/
		
	}


	
	
}