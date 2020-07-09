package main;

import java.lang.StackWalker.Option;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

//I did use https://commons.apache.org/proper/commons-cli/usage.html to help with understanding the useage of apache commons
//I'm not sure if I should include this but figured I better as I had to refer to it often.
public class AnagramCLI {
	
	private static AnagramEvaluatorImpl wordEvaluator = new AnagramEvaluatorImpl();
	static List<String> anagramList = new ArrayList<>();
	static String argsString = new String();
	//getter to get the list for testing
	public static List<String> getAnagramList() {
		return anagramList;
	}
	public AnagramCLI() {
		// TODO Auto-generated constructor stub
	}
	
	public AnagramCLI(String[] args) {
				
		//creates a CommandLine to be able to parse through 
		CommandLine cmd = null;
		//boolean used to validate if the program should run
		boolean runCli = false;
      
		//used to create the options(got help from the header website)
		  Options options = new Options();
		// create options objects
	      options.addOption("a", "anagram", true, "Supplies the anagram to evaluate");
	      options.addOption("nf", "no-filter", false, "output all anagram values with no filter");
	      options.addOption("words","filter-words", false, "output only values that are known words");
	      options.addOption("h", "help", false, "displays the help for this program");

	      //parser to be able to add options and a string to
	      CommandLineParser parser = new DefaultParser();
	      //attempts to run the parser with the given input from the user(got help from the header website)
	      try {
	    	  //parses the command line arguments
			cmd = parser.parse(options, args);
			//if the parser pases then it passes true to run
			runCli = true;
		}
	      //catches any errors from bad options being sent in and prints an invalid statement
	      catch (ParseException e) {
			// prints the invalid statement
			System.out.print("Invalid Option\n\nMissing required option: -a\n\n");
		    //sets the runCli to false and doesn't run the program 
			runCli = false;
		}
	      //if the runCli is true this runs
		if(runCli = true) {		
		      //hasOptions checks if option is present or not
		    if(cmd.hasOption("h")) {	 
		    	//used to create the help option
				HelpFormatter formatter = new HelpFormatter();
				//outputs the help options to the user
			    formatter.printHelp("options", options, true);
			      }  
		    //if the user sends in option a then it goes to the next options
			if(cmd.hasOption("a")) { 
		    	  //if the option also has a nf or words option
			      if(cmd.hasOption("nf")) {   
			    	  System.out.print("\n\n");
			    	  //runs the evaluate method from the AnagramEvaluatorImpl class and returns the result as a list
			    	  anagramList =	wordEvaluator.evaluate(cmd.getOptionValue("a"), "nf");
			    	  //final sorts the list to alphabetical order
			    	  Collections.sort(anagramList);
			    	  //outputs the number of values found to the user
			    	  System.out.print("\n-- " + anagramList.size() + " value(s) found\n");
			      }
			      if(cmd.hasOption("words")) {   
			    	  System.out.print("\n\n");
			    	//runs the evaluate method from the AnagramEvaluatorImpl class and returns the result as a list
			    	  anagramList = wordEvaluator.evaluate(cmd.getOptionValue("a"), "words");
			    	//final sorts the list to alphabetical order
			    	  Collections.sort(anagramList);
			    	//outputs the number of values found to the user
			    	  System.out.print("\n-- " + anagramList.size() + " value(s) found\n");
			    	  }
		      }    	
		      else if(cmd.hasOption("nf")) {
		    	  //outputs to the user is they didn't use an -a statement but tried to use an -nf
		    	  System.out.print("\n\nMissing required option: -a\n\n");
		      }
		      else if(cmd.hasOption("words")) {
		    	//outputs to the user is they didn't use an -a statement but tried to use an -words
		    	  System.out.print("\n\nMissing required option -a\n\n");
		      }
		}
	}
	//main method to run the program
public void main(String[] args) {
	//outputs to the user the option they have selected
	 System.out.print("Anagrammer ");
	for (int i = 0; i < args.length;i++) {
		System.out.print(args[i] + " ");
	}
	
	//calls this program with the given statements from the given CommandLine
	new AnagramCLI(args);
	System.out.print("\n");
}

}
