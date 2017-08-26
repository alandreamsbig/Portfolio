/*********************
 * TrueFalse class
 * 
 * Description: Creates True/False question 
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

public class TrueFalse extends MultipleChoice
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -3729884371666330625L;
	private String questionType = "True/False";
	
	public TrueFalse(String p)
	{
		this.addChoices("T/F");
		this.setQuestionType(questionType);
		this.prompt = p;
		
	}
	
	public String getQuestionType()
	{
		return questionType;
	}
	
	
}