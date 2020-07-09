package edu.Sinclair;

import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Test;
import main.*;

class AnagramCLITest {
	//Creates an instance to test
	AnagramCLI test = new AnagramCLI();
	
	//test to see if the help option runs
	@Test
	void testHelp() {
	//Creates a string to test
	String testString = "-h";
	//converts string to an array
	String[] codes = testString.split(" ");
	//sends the array into AnagramCLI to be tested
	test.main(codes);
	//if the code runs the it will get to this assert statement and then it will return true
	//if the code fails to run the whole test will fail
	assertTrue(true);
	}
	@Test
	void testWrongOption() {
		//Creates a string to test
	String testString = "-o";
	//converts string to an array
	String[] codes = testString.split(" ");
	//this code should fail to a try is made to attempt it
	try {
		//sends the array into AnagramCLI to be tested
	 test.main(codes);
	 //this code is meant to fail to pass
	 fail("Should have failed to find option");
	   } 
	//the code should be caught here as it failed
	catch (final RuntimeException e) {
		//asserts the test is true as the code failed
	       assertTrue(true);
	   }
	}
	@Test
	void testBakeWord() {
		//Creates a string to test
		String testString = "-nf -a DOG";
		//converts string to an array
		String[] codes = testString.split(" ");
		//Creates a list to save the anagrams to
		List<String> anagramList = new ArrayList<>();
		//creates a list to test against the anagram list
		List<String> testList = new ArrayList<>();
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//gets the anagram list from AnagramCLI
		anagramList = AnagramCLI.getAnagramList();
		testList.add("DGO");
		testList.add("DOG");
		testList.add("GDO");
		testList.add("GOD");
		testList.add("ODG");
		testList.add("OGD");
		//tests that the anagramList is the same as the testList
		assertEquals(anagramList,testList);
	}

	@Test
	void testBakeNf() {
		//Creates a string to test
		String testString = "-no-filter -a DOG";
		//converts string to an array
		String[] codes = testString.split(" ");
		//Creates a list to save the anagrams to
		List<String> anagramList = new ArrayList<>();
		//creates a list to test against the anagram list
		List<String> testList = new ArrayList<>();
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//gets the anagram list from AnagramCLI
		anagramList = AnagramCLI.getAnagramList();
		//adds to the test list as this should be the desired output
		testList.add("DGO");
		testList.add("DOG");
		testList.add("GDO");
		testList.add("GOD");
		testList.add("ODG");
		testList.add("OGD");
		//tests that the anagramList is the same as the testList
		assertEquals(anagramList,testList);
	}
	@Test
	void testNoAWithNf() {
		//Creates a string to test
		String testString = "-nf";
		//converts string to an array
		String[] codes = testString.split(" ");
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//if the code runs the it will get to this assert statement and then it will return true
		//if the code fails to run the whole test will fail
		assertTrue(true);
	}
	@Test
	void testNoAWithWords() {
		//Creates a string to test
		String testString = "-words";
		//converts string to an array
		String[] codes = testString.split(" ");
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//if the code runs the it will get to this assert statement and then it will return true
		//if the code fails to run the whole test will fail
		assertTrue(true);
	}
	
	@Test
	void DogFilterWords() {
		//Creates a string to test
		String testString = "-words -a DOG";
		//converts string to an array
		String[] codes = testString.split(" ");
		//Creates a list to save the anagrams to
		List<String> anagramList = new ArrayList<>();
		//creates a list to test against the anagram list
		List<String> testList = new ArrayList<>();
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//gets the anagram list from AnagramCLI
		anagramList = test.getAnagramList();
		//adds to the test list as this should be the desired output
		testList.add("DOG");
		testList.add("GOD");
		//tests that the anagramList is the same as the testList
		assertEquals(anagramList,testList);
	}
	@Test
	void testDogFilterWords() {
		//Creates a string to test
		String testString = "-filter-words -a DOG";
		//converts string to an array
		String[] codes = testString.split(" ");
		//Creates a list to save the anagrams to
		List<String> anagramList = new ArrayList<>();
		//creates a list to test against the anagram list
		List<String> testList = new ArrayList<>();
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//gets the anagram list from AnagramCLI
		anagramList = test.getAnagramList();
		//adds to the test list as this should be the desired output
		testList.add("DOG");
		testList.add("GOD");
		//tests that the anagramList is the same as the testList
		assertEquals(anagramList,testList);
	}

	@Test
	void testBakeNfdelets() {
		//Creates a string to test
		String testString = "-no-filter -a GRAD";
		//converts string to an array
		String[] codes = testString.split(" ");
		//Creates a list to save the anagrams to
		List<String> anagramList = new ArrayList<>();
		//sends the array into AnagramCLI to be tested
		test.main(codes);
		//gets the anagram list from AnagramCLI
		anagramList = AnagramCLI.getAnagramList();
		//tests that the anagramList is 24 (4!)
		assertEquals(anagramList.size(),24);
	}
}
