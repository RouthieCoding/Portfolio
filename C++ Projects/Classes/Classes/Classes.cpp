// Ryan Routhier
// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 07/17/2019
//This program allows the user to enter information about a book into a book class in order to learn how classes work. The program will store the information in the book class and then will
// check a copy of the book out and display this to the user. It will then return a copy of the book and display that to the user as well.
#include "pch.h"
#include <iostream>
#include <string>
#include "BookClass.h"

using namespace std;
//Asks the user to enter information for one book, then invokes member function storeBook to store the information in the BookClass variable
void getBookInfo(BookClass &testBook)
{
	string bookTitle, authorName, bookPublisher, bookISBN;
	double bookPrice= 1;
	int bookYear = 2001, booksInStock = 0;

	cout << "Enter book information \n";

	cout << "Enter book title: ";
	getline(cin, bookTitle);

	cout << "Enter author name: ";
	getline(cin, authorName);

	cout << "Enter book publisher: ";
	getline(cin, bookPublisher);

	cout << "Enter book ISBN: ";
	cin >> bookISBN;
	cin.ignore();

	cout << "Enter book price: ";
	cin >> bookPrice;
	cin.ignore();

	cout << "Enter year published: ";
	cin >> bookYear;

	cout << "Enter the number of books in stock: ";
	cin >> booksInStock;
	cout << endl;
	//calls the function inside of the book class to store information about the books
	testBook.storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
	
}


int main()
{
	BookClass testBook;

	// to store the book information into the BookClass variable
	getBookInfo(testBook);
	testBook.displayBookInfo(testBook);
	//to call function to check one book out
	testBook.checkOutBook(testBook);
	
	// to get the book’s title
	cout << "\n " << testBook.getTitle();

	// to get the number of copies currently in stock
	cout << " " << testBook.getNumInStock() << " remaining in stock\n" << endl;

	//calls function to return one book
	testBook.returnBook(testBook);

	//Display the book’s title and number of copies in stock 
	cout << endl << testBook.getTitle();
	cout << " " << testBook.getNumInStock() << "  remaining in stock\n";

}
	
