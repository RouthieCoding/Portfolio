
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//creats a class to store book information
class BookClass
{
	string title, author, publisher, isbn;
	double price = 0;
	int year = 0000, numInStock = 0, counter = 0;

public:
	//setters
	void storeBook(string, string, string, string, double, int, int);
	void setTitle(string);
	void setNumInStock(int);
	void displayBookInfo(BookClass);
	void checkOutBook(BookClass &);
	void returnBook(BookClass &);

	//getters
	string getTitle() { return title; }
	string getIsbn() { return isbn; }
	string getAuthor() { return author; }
	string getPublisher() { return publisher; }
	double getPrice() { return price; }
	int getYear() { return year; }
	int getNumInStock() { return numInStock; }



};

