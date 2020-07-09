//Ryan Routhier
//C-Strings.cpp
//6/17/19
// This program takes a company customer order number and breaks it down into all the seperate parts. It will the display to the user all these parts in an organized easy to read mannor.

#include "pch.h"
#include <iostream>
#include <cctype>
#include <stdio.h>

using namespace std;

//to find the location of w in the number
int findW(char order[], int count)
{
	while (order[count] != 'w')
	{
		count++;
	}
	return count;
}
// to find out the customer number and then return that as a long
long getCustNum(char order[], int count)
{
	char customer[5];
	long customerNum;
	
	for (int i =0; i < count;i++)
	{
		customer[i] = order[i];
	}
	customerNum= atol(customer);
	return customerNum;
	//strcat(order, customer, 5);
}

//to find out the year of the order and then return that as a int
int getYear(char order[], int count)
{
	char holder[2];
	int year;

	for (int i = count + 1; i < count +3; i++)
	{
		holder[i - (count + 1)] = order[i];
	}
	year = atoi(holder);
	return year;
}
//to find out the order number and then return that as a long
long getOrderNum(char order[], int count)
{
	char num[5];
	long orderNum;
	int length = strlen(order);
	for (int i = count + 3; i < length; i++)
	{
		num[i - (count +3)] = order[i];
	}
	orderNum = atol(num);
	return orderNum;
}
int main()
{
	int count = 0, year;
	char workOrder[20];
	long customerNum, orderNum;

	//to display to the user a set of rules that the program goes by
    cout << "Enter a three part work order code in the format CustomerNumber Number Year OrderNumber\n\n"
		 << "The first 5-6 digits contain the work order number (digits before the w)\n"
		 << "The 2 digits following the w represent the year\n"
		 << "The remaining digits (up to 5) represnt the work order number\n"
		 << "Enter work order code: ";
	cin >> workOrder;
	
	// displays the breakdown to the user
	cout << "\nWork order breakdown" << endl;
	//displays the length
	cout << "Length = " << strlen(workOrder) << endl;
	//displays the location of w
	count = findW(workOrder, count);
	cout << "Location of w = " << count << endl;
	//displays the customer number
	customerNum = getCustNum(workOrder, count);
	cout << "Customer number = " << customerNum << endl;
	//displays the order year
	year= getYear(workOrder,count);
	cout << "Year of order = " << year << endl;
	//displays the order number
	orderNum = getOrderNum(workOrder, count);
	cout << "Order number = " << orderNum << endl;
	
	 

	
}
