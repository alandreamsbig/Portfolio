import java.util.ArrayList;
import java.util.Scanner;

public class TestMenuLoop
{
	private ArrayList<Survey> testList = new ArrayList<Survey>();
	
	public TestMenuLoop()
	{
		
	}

	public int TestSelect(String args) 
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
	
			}while (choice < 1 && choice > 5);
			
			Survey survey = null;
			
			switch (choice)
			{
			case 1:
				//Audio o = new Audio();
				survey = new Survey();
				survey.createST(args);
				testList.add(survey);
				
				break;
	
			case 2:
				System.out.println("Select a test to display: ");
				for (int i=0; i < testList.size(); i++)
				{
					System.out.println((i+1) + " " + testList.get(i).getSurveyName());
				}
				
				int surveySelect = Integer.parseInt(Survey.scanner.nextLine());
				System.out.println(surveySelect);
				testList.get(surveySelect-1).display();
				
				break;
	
			case 3:
				LoadSave loadFile = new LoadSave();
				
				System.out.println("Enter a file name to load: ");
				String fileName = Survey.scanner.nextLine();
				Survey loaded = loadFile.load(fileName);
				testList.add(loaded);
				
				
				
				break;
			case 4:
				LoadSave saveFile = new LoadSave();
				for (int i=0; i < testList.size(); i++)
				{
					System.out.println((i+1) + " " + testList.get(i).getSurveyName());
				}
				
				int surveySave = Integer.parseInt(Survey.scanner.nextLine());
				saveFile.save(testList.get(surveySave-1));
				break;
			case 5:
				
				break;
	
	
			}
		
			
		return choice;
	
	
	}
	
}