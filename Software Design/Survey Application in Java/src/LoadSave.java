import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class LoadSave implements java.io.Serializable
{

	/**
	 * 
	 */
	private static final long serialVersionUID = 3052453376808670838L;
	
	public LoadSave()
	{
		
	}
	
	public void save(Survey d)
	{
		File theDir = new File("SurveyTest");

		// if the directory does not exist, create it
		if (!theDir.exists()) {
		    System.out.println("creating directory: " + "SurveyTest");
		    boolean result = false;

		    try{
		        theDir.mkdir();
		        result = true;
		        
		    } 
		    catch(SecurityException se){
		        //handle it
		    }        
		    if(result) {    
		        System.out.println("DIR created");  
		    }
		}
		
		try
		{
		String userDir = theDir.getAbsolutePath();
		File outf = new File(theDir, d.getSurveyName() + ".ser");
		FileOutputStream file = new FileOutputStream(outf);
		ObjectOutputStream fileOut = new ObjectOutputStream(file);
		fileOut.writeObject(d);
		fileOut.close();
		file.close();
		System.out.println("File " + d.getSurveyName() + " have been saved\n");
		} 
		catch (IOException i)
		{
			System.out.println("Error Saving Test/Survey\n");
		}
	}
	
	public Survey load(String name)
	{
		try
		{
			File theDir = new File("SurveyTest");
			String userDir = theDir.getAbsolutePath();
			String fileDir = userDir + "\\" + name + ".ser";
			File inf = new File(theDir, name + ".ser");
			FileInputStream fileIn = new FileInputStream(inf);
			ObjectInputStream loadFile = new ObjectInputStream(fileIn);
			Survey loaded = (Survey) loadFile.readObject();
			loadFile.close();
			fileIn.close();
			System.out.println("The file has been loaded\n");
			return loaded;
		}
		catch(Exception e)
		{
			System.out.println("Error loading Test/Survey\n");
		}
		return null;
	}
}
	
	
	
