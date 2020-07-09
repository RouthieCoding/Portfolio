// Ryan Routhier
// Baseball1.cpp week 1 assignment 
// Cis 1202
// 5/18/2019
/* This program takes input given to it in the form of a text document (baseball.txt) in function loadArrays. The program then displays the data to the user from function printStats. It then takes that data and finds out the 
teams batting averages in function calcBatAvg. Lastly the program finds the best and worst player on each team and displays that to the user.*/

#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// prototypes
void loadArrays(int[], int[], int[], int[], int[], int );
void calcBatAvg(int[], int[], int[], int);
void printStats(int[], int[], int[], int[], int[], int[], int);

//global variable
const int SIZE = 20;

int main()
{
	int playerNum[SIZE], atBats[SIZE], hits[SIZE], runs[SIZE], rbis[SIZE], batAvg[SIZE], i = 0, playerCount = 10, batAvgAccum = 0, teamAvg, bestAvg = 0, bestPlayer, worstAvg = 1000, worstPlayer = 0;

	//call function to load data back into main 
	loadArrays(playerNum, atBats, hits, runs, rbis, playerCount);

	//call function to load data for battin averages
	calcBatAvg(atBats, hits, batAvg, playerCount);
	
	// show user the information given
	printStats(playerNum, atBats, hits, runs, rbis, batAvg, playerCount);

	//Math Calculations 

	for (i = 0; i < playerCount; i++)
	//to accumulate batting average for the team
	{
		batAvgAccum += batAvg[i];
		
	//to find best and worst players
		if (bestAvg < batAvg[i])
		{
			bestAvg = batAvg[i];
			bestPlayer = playerNum[i];
		}
		if (batAvg[i] < worstAvg)
		{
			worstAvg = batAvg[i];
			worstPlayer = playerNum[i];
		}
	}
	//calculates team bat average
		teamAvg = batAvgAccum / playerCount;
	
	//displays the findings to user
	cout << "\nThe Team Batting Average is: " << teamAvg << endl;
	cout << "The Best Player is Player Number: " << bestPlayer << " with batting average of " << bestAvg << endl;
	cout << "The Worst Player is Player Number: " << worstPlayer << " with batting average of " << worstAvg << endl;


}

// to load data into the arrays
void loadArrays(int playerNum[], int atBats[], int hits[], int runs[], int rbis[], int playerCount)
{
	int i = 0;
	//open baseball text file
	ifstream baseball;
	baseball.open("baseball.txt");
	//loads data into respective array
	while (baseball >> playerNum[i] >> atBats[i] >> hits[i] >> runs[i] >> rbis[i])
	{
		i++;
		// to accumulate player amount
		playerCount += 1;
	}
}

// to load bat average data into array
void calcBatAvg(int atBats[], int hits[], int batAvg[], int playerCount)
{
	double avgPlaceholder;
	
		for (int i = 0; i < 10; i++)
			// uses average placeholder to help the rounding of its decimal
	{
			avgPlaceholder = hits[i] / double(atBats[i]) * 1000;
			avgPlaceholder= round(avgPlaceholder);
			batAvg[i] = avgPlaceholder;
	}
}

//to display data to the user
void printStats(int playerNum[], int atBats[], int hits[], int runs[], int rbis[],int batAvg[],  int playerCount)
{
	string comment = " ";
	
	//displays data and finds comment for each player
	cout << "Baseball Stats\n\n     Player Num   " << "At Bats\t" << "Hits\t   " << "Runs\t\t" << "RBI's\t  " << "Bat Avg   " << "Comment\n";
	for (int i = 0; i < playerCount; i++)
	{
		if (batAvg[i] >= 500 && batAvg[i] <= 1000) 
		{
			comment = "World Series";
		}
		else if (batAvg[i] >= 300 && batAvg[i] <= 499)
		{
			comment = "Farm League";
		}
		else if (batAvg[i] >= 0 && batAvg[i] <= 299)
		{
			comment = "Little League";
		}

		cout << right << setw(10) <<playerNum[i] << setw(11) << atBats[i] << setw(14) <<hits[i] << setw(10) <<runs[i] << setw(13) <<rbis[i] << setw(13) << batAvg[i] << "   " << left << setw(10) << comment << " \n";
	}

}


