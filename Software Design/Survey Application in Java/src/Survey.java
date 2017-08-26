/*********************
 * Survey class
 * 
 * Description: Creates test or survey 
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */





import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import com.sun.speech.freetts.Voice;
import com.sun.speech.freetts.VoiceManager;

public class Survey implements java.io.Serializable
{
	/**
	 * 
	 */
	private static final long serialVersionUID = -5990731629181663684L;
	/**
	 * 
	 */

    
   
	private String name;
	private ArrayList<Question> question;
	private ArrayList<String> AnswerList = new ArrayList<String>();
	private ArrayList<String> ResponseList = new ArrayList<String>();
	public static Scanner scanner = new Scanner(System.in);
	public String ST;
	
	
	public Survey()
	{
		question = new ArrayList<Question>();
	
	}
	
	public void setSurveyName(String surveyName)
	{
		name = surveyName;
	}
	
	public String getSurveyName()
	{
		return name;
	}
	
	public void addQuestion(Question q)
	{
		question.add(q);
	}
	
	public ArrayList<Question> getQuestion()
	{
		return question;
	}
	
	
	//Creates survey or test depending on what pass through 
	public void createST(String args)
	{
		ST = args;
		
		if (args.equals("Survey"))
		{
			System.out.println("Survey Name: ");
			
			String surveyName = scanner.nextLine();
			this.name = surveyName;
			
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
		//Creates test
		else if(args.equals("Test"))
		{
			createTest();
		}
		else
		{
			System.out.println("Invalid input");
			System.exit(0);
		}
		
		
		
	}
	
	//Display the prompt and or answer if it is a test
	public void display()
	{
		for (int i=0; i < question.size(); i++)
		{
			question.get(i).displayQuestion();
			if (ST == "Test")
			{
				System.out.println("User response: " + ResponseList.get(i) + "\n");
				System.out.println("The correct answer is: " + AnswerList.get(i) + "\n");
			}
			System.out.println("\n");
		}
		
	}
	
	
	public void modify(int modSelect)
	{
		question.get(modSelect-1);
		System.out.println("\nEnter a new prompt");
		String modding = Survey.scanner.nextLine();
		Question q = question.get(modSelect-1);
		q.setQuestion(modding);
	}
	
	public void questionLoop()
	{
		
		for(int i= 0; i < question.size(); i++)
		{
			question.get(i).displayQuestion();
			String response = scanner.nextLine();
			ResponseList.add(response);
		}
	}
	
	public void responseLoop()
	{
		for(int i= 0; i < ResponseList.size(); i++)
		{
			Random rand = new Random();
			int randomNum = rand.nextInt((3 - 0) + 1) + 0;
			question.get(i).displayQuestion();
			System.out.println(ResponseList.get(i) + "  Tabulate result: " + randomNum + "\n");
		}
	}
	
	public void grading()
	{
		int count = 0;
		for (int k = 0; k < question.size(); k++)
		{
			
			question.get(k).displayQuestion();
			System.out.println("Your response is: " + ResponseList.get(k) + "\n");
			System.out.println("The correct answer is: " + AnswerList.get(k) + "\n");
			if (ResponseList.get(k).equals(AnswerList.get(k)))
			{
				System.out.println("Score: 1/1" + "\n");
				count++;
			}
			else
			{
				System.out.println("Score: 0/1" + "\n");
			}
			
		
		}
		System.out.println("\n");
		System.out.println("Total test score: " + count + "/" + question.size() + "\n");
	
	}
		
	
	//Create test function
	public void createTest()
	{
		System.out.println("Test Name: ");
		
		String surveyName = scanner.nextLine();
		this.name = surveyName;
		
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
			
			System.out.println("Enter a True/False answer: ");
			String TFanswer = scanner.nextLine();
			AnswerList.add(TFanswer);
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
			
			System.out.println("Enter the answer for Multiple question:  ");
			String MCanswer = scanner.nextLine();
			AnswerList.add(MCanswer);
			choice = -1;
			break;
			
		case 3:
			
			System.out.println("Enter a question for short answer: ");
			Scanner SA = new Scanner(System.in);
			String SAquestion = SA.nextLine();
			
			ShortAnswer SAq = new ShortAnswer(SAquestion);
			addQuestion(SAq);
			System.out.println("Enter the answer for short answer question:  ");
			String Shortanswer = scanner.nextLine();
			AnswerList.add(Shortanswer);
			choice = -1;
			break;
			
		case 4:
			
			System.out.println("Enter a question for essay: ");
			Scanner ES = new Scanner(System.in);
			String Equestion = ES.nextLine();
			Essay Eq = new Essay(Equestion);
			addQuestion(Eq);
			System.out.println("Enter the answer for essay question:  ");
			String EssayAnswer = scanner.nextLine();
			AnswerList.add(EssayAnswer);
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
			System.out.println("Enter the answer for ranking question:  ");
			String RankingAnswer = scanner.nextLine();
			AnswerList.add(RankingAnswer);
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
			System.out.println("Enter the answer for Matching question:  ");
			String MatchingAnswer = scanner.nextLine();
			AnswerList.add(MatchingAnswer);
			choice = -1;
			break;
			
		case 7:
			break;
		}
		
		}
	
	}
	
	
}