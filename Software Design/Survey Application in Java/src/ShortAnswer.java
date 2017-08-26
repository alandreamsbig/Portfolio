/*********************
 * ShortAnswer class
 * 
 * Description: Creates short answer question
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

public class ShortAnswer extends Essay
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 6957477181547292112L;
	private String questionType = "Short Answer";
	
	
	public ShortAnswer(String p)
	{
		this.setQuestionType(questionType);
		this.prompt = p;
		
	}
	
	public String getQuestionType()
	{
		return questionType;
	}
	
}