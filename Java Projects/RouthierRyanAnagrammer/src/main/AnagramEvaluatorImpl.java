package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class AnagramEvaluatorImpl implements AnagramEvaluator{
	//List to be returned to CLI
	static List<String> anagramList = new ArrayList<>();
	//constructor
	public AnagramEvaluatorImpl() {	
	}
	
 //method to sort a string to output all anagram values 	
 private static List<String> stringLettersSort(String anagram, int first, int last) 
 { 
	 //holds a letter of the anagram
	char holder; 
	//turns the anagram string into a char
    char[] anagramChar = anagram.toCharArray();
  
    //base case
    if (first == last) {
    	//builds list
	anagramList.add(anagram);
    }
    else
    { 
    	//loops through the letters of the anagram string
        for (int i = first; i <= last; i++) 
        {          
        	//goes through the anagram to be able to save that new value to the base case list
        	holder = anagramChar[first] ; 
        	anagramChar[first] = anagramChar[i]; 
        	anagramChar[i] = holder;
            anagram = new String(anagramChar);
            //recursive statement to move the first letter to the next letter
            stringLettersSort(anagram, first+1, last); 
        } 
    }
	return anagramList; 
} 
//method to take in the option and a string to output the proper option
	public List<String> evaluate(String anagram, String option) {
		//class that reads in data from file 
		AnagramDataReaderImpl wordReader = new AnagramDataReaderImpl();
		//set holds the data being read in and doesn't allow duplicates
		Set<String> realWords = wordReader.readData();
		//allows to move through each item of the set
		Iterator<String> realWordsIterator = realWords.iterator();
		//set used to get rid of duplicates
		Set<String> anagramSet = new HashSet<>();
		//list used to be the returned list
		List<String> anagramWordList = new ArrayList<>();
		 //if option equals nf
		if (option.equals("nf")) {
			//clears the list (will allow this program to loop)
			 anagramList.clear();
			//int to hold size of the anagram
	    	  int size = anagram.length(); 	
	    	  //calls the method stringLettersSort to sort all letter options and return that to a list
		      anagramList = stringLettersSort(anagram, 0, size-1);	
		      //converts the list in a set to rid all duplicates
		      for (String holder: anagramList) {
		    	  anagramSet.add(holder);
		      }
		      //clears the origional list
		      anagramList.clear();
		      //converts the set back into a list
		      for (String holder: anagramSet) {
		    	  anagramList.add(holder);
		      }
		      //sorts the list in alphabetical order
		      Collections.sort(anagramList);
		      //outputs the list to the user
		      for (String holder: anagramList) {
		    	  System.out.println(holder);
		      }
		}
		//if the option being sent in is words
		if (option.equals("words")) {
			//clears the list of all previous data
			anagramWordList.clear();
			// Creating array of string length 
	          char[] anagramChar = new char[anagram.length()];     
	          // Copy character by character into array 
	          for (int i = 0; i < anagram.length(); i++) { 
	        	  anagramChar[i] = anagram.charAt(i); 
	          } 
	          //sorts the word in order
	          Arrays.sort(anagramChar);
	          //saves that new ordered char array as a word
	          String finalAnagram = new String(anagramChar);
	          //reads in data from file
	      while (realWordsIterator.hasNext()){
	    	  //save the next value in the file as a string
	    	String realWordsString = realWordsIterator.next();
	    	//changes that string into a char array
	    	char[] wordOutput = realWordsString.toCharArray();
	    	//sorts that char array
	    	Arrays.sort(wordOutput);
	    	//saves the sorted array as a string
	    	String finalRealWord = new String(wordOutput);
	    	//if the anagram option sorted string equals the sorted word from the file
	        if (finalAnagram.equals(finalRealWord)) {
	        	//adds the original unsorted word to the list
	        	anagramWordList.add(realWordsString);
	        	//outputs original word given
	        	System.out.println(realWordsString); 
	        	}
	      }
	      //saves the word list to the anagram list
	      anagramList = anagramWordList;
		}
		//returns the proper list needed for the given option
		return anagramList;
	}
	
}
