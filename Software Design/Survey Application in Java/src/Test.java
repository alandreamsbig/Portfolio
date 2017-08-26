/*********************
 * Test class
 * 
 * Description: Creates a test 
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class Test extends Survey 
{
	private ArrayList<Answer> AnswerList = new ArrayList<Answer>();
	private String questionType = "Answer";
	private String prompt;
	
	public Test()
	{
		
	}
	
	public void Answer(String t)
	{
		this.prompt = t;
	}

	public ArrayList<Answer> getAnswer()
	{
		return AnswerList;
	}
	
	public void setAnswer(ArrayList<Answer> a)
	{
		AnswerList = a;
	}
	
	public void addAnswer(Answer addAns)
	{
		AnswerList.add(addAns);
	}
	
	
	public String getQuestionType()
	{
		return questionType;
	}

	@Override
	public void createTest()
	{
		System.out.println("Test Name: ");
		
		
		String surveyName = scanner.nextLine();
		this.setSurveyName(surveyName);
		
		int choice = -1;
		
		while (choice != 7)
		{
			System.out.println("1) Add a new T/F question");
			System.out.println("2) Add a new multiple choice question");
			System.out.println("3) Add a new short answer question");
			System.out.println("4) Add a new essay question");
			System.out.println("5) Add a new ranking question");
			System.out.println("6) Add a new matching question");
			System.out.println("7) Return to Menu");
		do
		{
			try
			{
				choice = Integer.parseInt(scanner.nextLine());
				
				if (choice < 1 && choice  >7)
				{
					throw new NumberFormatException();
				}
			}
			catch(NumberFormatException e)
			{
				System.out.println("Wrong inuput entered. Please select 1 ~ 7");
				choice = -1;
			}
		
		}while (choice < 1 && choice > 7);
		
		switch (choice)
		{
		case 1:
			
			System.out.println("Enter a True/False question: ");
			String TFquestion = scanner.nextLine();
			TrueFalse TFq = new TrueFalse(TFquestion);
			addQuestion(TFq);
			
			System.out.println("Enter answer for True/False: ");
			String TFanswer = scanner.nextLine();
			//TrueFalse TFa = new TrueFalse(TFanswer);
			//addAnswer(TFanswer);
			choice = -1;
			break;
		
		case 2:
			
			System.out.println("Enter a multiple choice question: ");
			Scanner MC = new Scanner(System.in);
			String MCquestion = MC.nextLine();
			System.out.println("Enter the number of choices for your multiple choice question: ");
			int MC_choice = Integer.parseInt(MC.nextLine());
			MultipleChoice MCq = new MultipleChoice(MCquestion);
			for (int i = 0; i < MC_choice; i++)
			{
				System.out.println("Choice #" + (i+1));
				MCq.addChoices(MC.nextLine());
			}
			addQuestion(MCq);
			choice = -1;
			break;
			
		case 3:
			
			System.out.println("Enter a question for short answer: ");
			Scanner SA = new Scanner(System.in);
			String SAquestion = SA.nextLine();
			
			ShortAnswer SAq = new ShortAnswer(SAquestion);
			addQuestion(SAq);
			choice = -1;
			break;
			
		case 4:
			
			System.out.println("Enter a question for essay: ");
			Scanner ES = new Scanner(System.in);
			String Equestion = ES.nextLine();
			Essay Eq = new Essay(Equestion);
			addQuestion(Eq);
			choice = -1;
			break;
			
		case 5:
			
			System.out.println("Enter a question for ranking: ");
			Scanner RA = new Scanner(System.in);
			String Rquestion = RA.nextLine();
		
			System.out.println("Enter the number of choices for your ranking question: ");
			int Rank = Integer.parseInt(RA.nextLine());
			Ranking Rq = new Ranking(Rquestion);
			for (int i = 0; i < Rank; i++)
			{
				System.out.println("Choice #" + (i+1));
				Rq.addChoices(RA.nextLine());
				
			}
			
			addQuestion(Rq);
			choice = -1;
			break;
			
		case 6:
			
			System.out.println("Enter a question for matching: ");
			Scanner MA = new Scanner(System.in);
			String Mquestion = MA.nextLine();
			System.out.println("Enter the number of choices for your matching question: ");
			int MatchChoice = Integer.parseInt(MA.nextLine());
			Matching Mq = new Matching(Mquestion);
			for (int i = 0; i < MatchChoice; i++)
			{
				System.out.println("Choice #" + (i+1));
				Mq.addLeft(MA.nextLine());
			
			}
			System.out.println("Enter the number of choices for your matching question: ");
			int Match = Integer.parseInt(MA.nextLine());
			for (int i = 0; i < Match; i++)
			{
				System.out.println("Choice #" + (i+1));
				Mq.addRight(MA.nextLine());
			
			}
			addQuestion(Mq);
			choice = -1;
			break;
			
		case 7:
			break;
		}
		
		}
	
	}
	
	
	/*
	@Override
	public void displayQuestion() {
		// TODO Auto-generated method stub
		System.out.println(prompt);
		for (int i=0; i < Choices.size(); i++)
		{
			System.out.println(Choices.get(i));
		}
	*/	
	
	
}