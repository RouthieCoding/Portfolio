// Ryan Routhier
// BinaryFile.cpp  
// 7/2/2019
// This program creates a binary file. Then uses that file to read product records from that file into output. You can display all the records at once or select just a single record. 
// Finallyn you can select and modify a product record and then it outputs that new data back into the binary file. 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int DESC_SIZE = 40; 

struct Product 
{ 
	long prodNum;  
	char prodName[DESC_SIZE];  
	double price;  
	int qty;
};

//To show menu in main
int showMenu(int menu)
{
	cout << "1 - Display product inventory\n"
		 << "2 - Display a particular product\n"
		 << "3 - Modify a product\n"
		 << "4 - Exit program\n\n"
		 << "Enter menu choice: ";
	cin >> menu;
	return menu;
}

//Function to makes the binary file for program
void makeFile(fstream &inventory)
{
	long prodNum[11] = { 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110 };
	char prodName[11][DESC_SIZE] = { "nuts", "bolts", "nails", "hammer", "screw-driver", "s-hook", "glue", "pliers", "saw", "L-bracket" };
	double price[11] = { 0.10, 0.20, 0.05, 10.00, 5.00, 0.50, 1.98, 7.95, 25.00, 1.95 };
	int qty[11] = { 600, 600, 1000, 65, 72, 20, 25, 6, 7, 25 };

	Product record[11];

	//clears out old file to start a new out
	//Remove if you want data saved in between use
	inventory.open("inventory.dat", ios::out | ios::binary);
	inventory.close();

	// make record array
	for (int i = 0; i < 10; i++)
	{
		record[i].prodNum = prodNum[i];

		for (int x = 0; x < DESC_SIZE; x++)
		{
			record[i].prodName[x] = prodName[i][x];
		}
		record[i].price = price[i];
		record[i].qty = qty[i];

		//To send data array into binary file 
		inventory.open("inventory.dat", ios::app | ios::binary);
		
		inventory << record[i].prodNum << "!";
		
		//loop to read data into char array
		for (int x = 0; x < DESC_SIZE; x++)
		{
			inventory << record[i].prodName[x];
		}
		inventory << "!" << setw(5) << left << fixed << setprecision(2) << record[i].price << "!" << setw(4) << left << setprecision(0) << record[i].qty << "*";

		//close inventory
		inventory.close();
	}
}
// Outputs all of inventory to the user
void printFile(fstream &inventory)
{
	string input;
	int count = 0;
	
	inventory.open("inventory.dat", ios::in | ios::binary);

	//loop to output all of the inventory
	while (inventory)
		{
		//added this getline here so when it's empty the loop closes and doesn't start the if statement
			getline(inventory, input, '!');
			
			//outputs inventory to use and counts each slot
			if (inventory)
				{
					cout << "Record #" << count << " Product Number: ";
					cout << input << endl << "Product Name: ";
					getline(inventory, input, '!');
					cout << input << endl << "Price: $";
					getline(inventory, input, '!');
					cout << input << endl << "Quantity: ";
					getline(inventory, input, '*');
					cout << input << endl << endl;;
					count++;
				}
			
			
		}
		
		inventory.close();
}
void displayRecord(fstream &inventory)
{
	
	string input;
	int lineLength, recNumber;
	double numberHolder;

	//to open and clear eof tag
	inventory.open("inventory.dat", ios::in | ios::binary);
	inventory.clear();
	inventory.seekg(0L, ios::beg);

	//To find the length of each line
	getline(inventory, input, '*');
	lineLength = input.length()+ 1;
	
	//close inventory
	inventory.close();

	cout << "Enter record number to be displayed: ";
	cin >> recNumber;

	//open inventory for displaying single record
	inventory.open("inventory.dat", ios::in | ios::binary);

	//Find out where to start reading data from
	lineLength *= recNumber;

	//start reading out record data to the user
	cout << "Record Number: "<< recNumber << endl;

	//seekg goes to correct spot for data output  
	inventory.seekg(lineLength, ios::beg);
	
	//for single use of data output
	if (inventory)
	{
		getline(inventory, input, '!');
		cout << "Product Number: " << input << endl;
		getline(inventory, input, '!');
		cout << "Product Name: " << input << endl;
		getline(inventory, input, '!');
		//makes sure all data is displayed with 2 decimals including new data entered
		numberHolder = stod(input);
		cout << "Price: $" << fixed << setprecision(2) << numberHolder << endl;
		getline(inventory, input, '*');
		cout << "Quantity: " << input << endl << endl;
		
	}
	inventory.close();
}
//to modify a record
void modifyRecord(fstream &inventory)
{
	Product newRecord;
	char prodName[DESC_SIZE];
	int lineLength, modNumber;
	string input;

	//to open and clear eof tag
	inventory.open("inventory.dat", ios::in | ios::binary);
	inventory.clear();
	inventory.seekg(0L, ios::beg);

	//To find the length of each line
	getline(inventory, input, '*');
	lineLength = input.length() + 1;

	//close inventory
	inventory.close();

	//prompt user for number to be modified
	cout << "Enter record number to be modified: ";
	cin >> modNumber;

	//to locate the row where the data is 
	lineLength *= modNumber;
	
	//To get the new record data from the user
	cout << "Enter the new data\nRecord Number: " << modNumber << endl;
	cout << "Product Number: ";
	cin >> newRecord.prodNum;
	cout << "Product Name: ";
	cin.ignore();
	cin.getline(prodName, DESC_SIZE);
	cout << "Price: $";
	cin >> newRecord.price;
	cout << "Quantity: ";
	cin >> newRecord.qty;
	cout << endl;

	//opens up the inventory
	inventory.open("inventory.dat", ios::in | ios::out | ios::binary);
	//seekp goes to corect spot for data input
	inventory.seekp(lineLength, ios::beg);
	//puts new record info into data
	inventory << newRecord.prodNum << "!";
	inventory << setw(DESC_SIZE) << left << prodName;
	inventory << "!";
	inventory << setw(5) << fixed<< setprecision(2) << newRecord.price;
	inventory << "!";
	inventory << setw(4) << newRecord.qty;
	inventory << "*";
	inventory.close();
	cout << "Record number " << modNumber << " updated" <<endl;
}


int main()
{
	
	int menuChoice = 0;
	bool loopBreak = false;
	fstream inventory;

	//makes the inventory binary file
	makeFile(inventory);

	//loop for running the program
	while (loopBreak != true)
	{
		//displays menu and returns option selected
		 menuChoice = showMenu(menuChoice);
		 
		 //switch to operate the menu
		 switch (menuChoice)
		{
		 case 1: printFile(inventory);
			break;
		 case 2: displayRecord(inventory);
			break;
		case 3: modifyRecord(inventory);
			break;
		case 4: loopBreak = true;
			break;
			// Validates user, lets them know they have entered the wrong data
		default: cout << "Please enter a valid option" << endl;
			break;
		}

	}
	return 0;
}

