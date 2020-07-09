
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "BookClass.h"

//stores data into the BookClass Class
void BookClass::storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock)
{

	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock = booksInStock;
}

//to change the title
void BookClass::setTitle(string setTitle)
{
	title = setTitle;
}
//to change the amount of items in stock
void BookClass::setNumInStock(int setNumInStock)
{
	numInStock = setNumInStock;
}


//Displays the contents of the BookClass member variables
void BookClass::displayBookInfo(BookClass temp)
{
	cout << temp.getTitle() << endl;
	cout << "Author: " << temp.getAuthor() << endl;
	cout << "Publisher: " << temp.getPublisher() << endl;
	cout << "ISBN: " << temp.getIsbn() << endl;
	cout << "Price: $" << fixed << setprecision(2) << temp.getPrice() << endl;
	cout << "Year: " << temp.getYear() << endl;
	cout << "Number of copies: " << temp.getNumInStock() << endl << endl;
}


//checks a book out and subtracts 1 from the numInStock member variable and tests to make sure numInStock is not 0
void  BookClass::checkOutBook(BookClass &numCheck)
{

	if (numCheck.getNumInStock() != 0)
	{
		cout << "book checked out \n";
		numCheck.setNumInStock(numCheck.getNumInStock() - 1);

	}
	else
	{
		cout << "Sorry all copies are out\n";
	}
}

//returns a book and adds 1 to the numInStock member variable
void  BookClass::returnBook(BookClass &numCheck)
{
	cout << "book returned \n";
	numCheck.setNumInStock(numCheck.getNumInStock() + 1);
}

