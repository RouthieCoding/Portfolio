//Ryan Routhier
//6/16/2019
// ArraysAndPointers.cpp 
// This program takes 5 rentals given to you from the user and displays them and the computer memory address location of these rentals. It can also take the rentals and sort them in order.
//THis is easy for the user to view.

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//Allows user to enter his 5 places he has for rent
void enterRents(int rentals[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter rent amount " << i + 1 << ":";
		cin >> rentals[i];
	}
}
 // displays the properities as entered
void displayRents(int *rentals, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Rental property " << i + 1 << " "<<  *(rentals + i)<< endl;
		
	}
}
//displays the memory location of the rentals
void displayMemoryLocations(int rentals[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Memory address of cell "<< i << " = " << &rentals[i] << endl;

	}
}
//sorts the rentals in order
void selectionSort(int rentals[],int n)
{
	int min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (rentals[j] < rentals[min])
				min = j;
			//min will keep track of the index 
		}

		//if min no longer equals i than a smaller value must have been found, then swap 
		if (min != i)
		{
			temp = rentals[i];
			rentals[i] = rentals[min];
			rentals[min] = temp;
		}
	}
}

int main()
{
	int getMenuItem = 0, rentals[5], propertyCount = 5;
	// main while loop for menu 
	while (getMenuItem != 5)
	{
		//menu for usert to see
		cout << "Sinclair Property Management\n\n"
			<< "Select from the following menu\n"
			<< "1 Enter rent amounts\n"
			<< "2 Display rents\n"
			<< "3 Sort rent amounts\n"
			<< "4 Display rent array memory locations\n"
			<< "5 Exit program\n\n"
			<< "Enter Selection: ";
		cin >> getMenuItem;
		//main switch to operate the menu
		switch (getMenuItem)
		{
		case 1:
			enterRents(rentals, propertyCount);
			break;
		case 2:
			displayRents(rentals, propertyCount);
			break;
		case 3:
			selectionSort(rentals, propertyCount);
			break;
		case 4:
			displayMemoryLocations(rentals, propertyCount);
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "Please enter a valid option\n";
			break;
		}
	}
}