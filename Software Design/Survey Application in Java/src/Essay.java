/*********************
 * Essay class
 * 
 * Description: Creates essay question
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

public class Essay extends Question implements java.io.Serializable
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String questionType = "Essay";
	
	public Essay()
	{
		
	}
	public Essay(String p)
	{
		this.setQuestionType(questionType);
		this.prompt = p;
	}
	
	public String getQuestionType()
	{
		return questionType;
	}
	
	@Override
	public void displayQuestion() {
		// TODO Auto-generated method stub
		o.send(prompt);
	}

	
}