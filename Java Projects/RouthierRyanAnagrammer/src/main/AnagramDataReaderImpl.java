package main;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class AnagramDataReaderImpl implements AnagramDataReader{

	@Override
	public Set<String> readData() {
		// set used to save the words from the file into
		Set<String> realWords = new HashSet<String>(); 
		//attempts to read the data from file anagram_data.txt 
		try {
			  //file used to hold the file name
		      File file = new File("anagram_data.txt");
		      //scanner used to get input from the file
		      Scanner fileReader = new Scanner(file);
		      //runs while the file has data to output
		      while (fileReader.hasNextLine()) {
		    	 //saves the next line as a string
		        String data = fileReader.nextLine();
		        //adds the word to the set list
		        realWords.add(data);
		      }
		      //closes the file
		      fileReader.close();
		    }//catch used to catch errors 
		catch (FileNotFoundException e) {
			//outputs to user an error happened
		      System.out.println("An error occurred.");
		      e.printStackTrace();
		    }
		//returns the set list realWords
		return realWords;
	}

}
