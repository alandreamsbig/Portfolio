/*********************
 * MenuLoop class
 * 
 * Handles the second menu for survey and test. Including create, display, save and load
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */


import java.util.ArrayList;
import java.util.Scanner;

public class MenuLoop
{
	private ArrayList<Survey> surveyList = new ArrayList<Survey>();
	
	public MenuLoop()
	{
		
	}

	public int MenuSelect(String args) 
	{
		int choice = -1;
	
			do 
			{
				try
				{
					choice = Integer.parseInt(Survey.scanner.nextLine());
					
					if (choice < 1 && choice  >5)
					{
						throw new NumberFormatException();
					}
				}
				catch(NumberFormatException e)
				{
					System.out.println("Wrong inuput entered. Please select the numbers 1 ~ 5");
					choice = -1;
				}
	
			}while (choice < 1 && choice > 9);
			
			Survey survey = null;
			
			switch (choice)
			{
			case 1:
				//Audio o = new Audio();
				survey = new Survey();
				survey.createST(args);
				surveyList.add(survey);
				break;
	
			case 2:
				System.out.println("Select a file to display: ");
				for (int i=0; i < surveyList.size(); i++)
				{
					System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
				}
				
				int surveySelect = Integer.parseInt(Survey.scanner.nextLine());
				System.out.println(surveySelect);
				surveyList.get(surveySelect-1).display();
				break;
	
			case 3:
				LoadSave loadFile = new LoadSave();
				System.out.println("Enter a file name to load: ");
				String fileName = Survey.scanner.nextLine();
				Survey loaded = loadFile.load(fileName);
				surveyList.add(loaded);
				break;
			
			case 4:
				LoadSave saveFile = new LoadSave();
				for (int i=0; i < surveyList.size(); i++)
				{
					System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
				}
				
				int surveySave = Integer.parseInt(Survey.scanner.nextLine());
				saveFile.save(surveyList.get(surveySave-1));
				break;
				
			case 5:
				System.out.println("Select a file to modify: ");
				for (int i=0; i < surveyList.size(); i++)
				{
					System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
				}
				
				int Select = Integer.parseInt(Survey.scanner.nextLine());
				surveyList.get(Select-1).display();
				Survey s = surveyList.get(Select-1);
				System.out.println("Select a question number to modify ");
				int modSelect = Integer.parseInt(Survey.scanner.nextLine());
				s.modify(modSelect);
				
				break;
			
			case 6:
				System.out.println("Enter a Survey/Test name to take: ");
				for (int i=0; i < surveyList.size(); i++)
				{
					System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
				}
				int take = Integer.parseInt(Survey.scanner.nextLine());
				Survey q = surveyList.get(take-1);
				q.questionLoop();
				
				break;
				
			case 7: 
				System.out.println("Enter a Survey/Test name to tabulate: ");
				for (int i=0; i < surveyList.size(); i++)
				{
					System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
				}
				int tabulate = Integer.parseInt(Survey.scanner.nextLine());
				Survey t = surveyList.get(tabulate-1);
				t.responseLoop();
				break;
				
			case 8:
				if(args == "Test")
				{
					System.out.println("Enter a Test name to grade: ");
					for (int i=0; i < surveyList.size(); i++)
					{
						System.out.println((i+1) + " " + surveyList.get(i).getSurveyName());
					}
					int grade = Integer.parseInt(Survey.scanner.nextLine());
					Survey g = surveyList.get(grade-1);
					g.grading();
					break;
				}
				else
				{
				break;
				}
			case 9:
				break;
				
			}
		
			
		return choice;
	
	
	}
	
}