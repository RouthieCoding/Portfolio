//Ryan Routhier
// MidTerm.cpp 
// 7/08/2019
/* This program is a casino style program that allows a user to enter in their personal information and then is awarded $10. They can use their money to play games
	which includes a cup guessing game, a high card(war) styled game and a blackjack styled game. Based on if the player wins or loses their total money is added or lost.
	The user can veiw the highscores for the games as well as search through them to find a certian person and the scores they got. The user can then cash their money out
	and if they are positive a check will be sent but if they are negative a bill will be sent.
	 */
#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
// i had to "_CRT_SECURE_NO_WARNINGS" in my project setting folder to get strncpy() to work
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//Global const
const int SIZE = 50, maxCards = 52;

//makes emuns to save card types
enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum cardValues { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct cards
{
	suits suit;
	cardValues card;
};

struct Address
{
	string street, city, state, zip;

};

struct Player
{
	string name;
	Address playerInfo;
};

//used to create a deck of cards
void createDeck(cards deck[])
{
	for (suits i = CLUBS; i <= SPADES; i = static_cast<suits>(i + 1))
	{
		for (cardValues x = TWO; x <= ACE; x = static_cast<cardValues>(x + 1))
		{
			deck[x + (i * (maxCards / 4))].suit = static_cast<suits>(i);
			deck[x + (i * (maxCards / 4))].card = static_cast<cardValues>(x);
		}
	}
}

//used to get a random card
void deal(cards deck[], cards &card)
{
	cards temp;

	temp.card = card.card;
	//srand(time(0));
	while (temp.card == card.card)
	{
		
		card = deck[rand() % maxCards];
	}
	srand(time(NULL));
	
}

//prints the value and type of card 
void printCard(cards print)
{
	switch (print.card) {
	case TWO:	cout << "Two";
		break;
	case THREE:	cout << "Three";
		break;
	case FOUR:	cout << "Four";
		break;
	case FIVE:	cout << "Five";
		break;
	case SIX:	cout << "Six";
		break;
	case SEVEN:	cout << "Seven";
		break;
	case EIGHT:	cout << "Eight";
		break;
	case NINE:	cout << "Nine";
		break;
	case TEN:	cout << "Ten";
		break;
	case JACK:	cout << "Jack";
		break;
	case QUEEN:	cout << "Queen";
		break;
	case KING:	cout << "King";
		break;
	case ACE:	cout << "Ace";
		break;
	}
	cout << " of ";
	// prints the suit of the card 
	switch (print.suit) {
	case CLUBS:	    cout << "Clubs";
		break;
	case DIAMONDS:	cout << "Diamonds";
		break;
	case HEARTS:	cout << "Hearts";
		break;
	case SPADES:	cout << "Spades";
		break;
	}
}

//Main menu Output
int showMenu(int choice)
{
	cout << "\nMake a selection\n"
		<< "1: Join now and get $10.00 FREE\n"
		<< "2: To play Magic Cups\n"
		<< "3: To play War\n"
		<< "4: To play BlackJack\n"
		<< "5: To veiw high scores \n"
		<< "6: To cashout \n"
		<< "7: To Exit\n\n"
		<< "Please choose a number: ";
	cin >> choice;
	cout << endl;
	return choice;
}
//User can enter their name and address for highscores and checks/billing
Player playerInfo(Player newPlayer[SIZE], double &cash, string &currentPlayer)
{
	Player temp;
	char lengthHolder[SIZE];
	int strLength;
	cin.ignore();
	cout << "Enter your full name: ";
	getline(cin, temp.name);
	currentPlayer = temp.name;

	cout << "We will also need your address to send you a check\n"
		<< "Enter street address: ";
	getline(cin, temp.playerInfo.street);

	cout << "Enter city: ";
	getline(cin, temp.playerInfo.city);

	cout << "Enter state: ";
	getline(cin, temp.playerInfo.state);

	cout << "Enter zip code: ";
	cin >> temp.playerInfo.zip;
	cin.ignore();
	
	//adds 10 dollars to the players wallet
	cash = 10;

	//finds how long their name is
	strLength = temp.name.length();

	//If their name is longer then 7 characters then they get an extra dollar
	if (strLength > 7)
	{
		cout << " Your name is " << strLength << " characters long, which is bigger then\n"
			<< "our lucky number of 7. You get an extra $1.00!\n";
		cash += 1;
	}
	cout << "\n\tThanks, "<< currentPlayer <<", you now have $" << fixed << setprecision(2) << cash << " in your account and are ready to gamble!\n";
	return temp;

}
//used in both War and Blackjack..Function takes 2 cards and declares an outcome
int winner(int card1, int card2, double &cash, int highScore)
{
	if (card1 > card2)
	{
		cout << "\n\tCongrats you Win!" << endl;
		cash += 1;
		highScore += 1;
	}
	else if (card1 < card2)
	{
		cout << "\n\tSorry you lost" << endl;
		cash -= 1;
		highScore -= 1;
	}
	else
	{
		cout << "\n\tIt's a draw" << endl;
	}
	return highScore;
}
//function used to decide if user wants to keep playing
bool playAgain(double cash)
{
	char decision[4];
	bool loopHelper = false;
	string temp;
	
	loopHelper = false;
	while (loopHelper != true)
	{
		cout << "You have $" << fixed << setprecision(2) << cash << " left\n";
		cout << "Do you want to play again? (yes or no)";
		cin >> decision;

		// used the tolower function to always return lower case letters
		for (int i = 0; i < 4; i++)
		{
			decision[i] = tolower(decision[i]);
		}
		temp = decision;
		//uses the converted string temp to return a true or false
		if (temp == "yes")
		{
			return true;
			loopHelper = true;
		}
		else if (temp == "no")
		{
			return false;
			loopHelper = true;
		}
		//validates user input
		else
		{
			cout << "\nYou wrote " << temp << " please enter yes or no\n";
		}
	}
}
//Shows player stats if they are in the top 5
void showPlayer(double score[SIZE][3],string player[SIZE][3], string playerSearch)
{
	bool startLoop = false;
	
	//searches to find if the user is in the top 5 already
	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (playerSearch == player[i][x])
			{
					startLoop = true;
			}
		}
	}
	//if player is found the while loop outputs the records and data associated with their name
		while (startLoop != false)
		{
			cout << endl << playerSearch << " has records in: " << endl;
			for (int i = 0; i < 5; i++)
			{
				if (playerSearch == player[i][0])
				{
					cout << setw(12) << "Magic Cups: " << i + 1 << " place with score of " << score[i][0] << endl;
				}
				if (playerSearch == player[i][1])
				{
					cout << setw(12) << "War: " << i + 1 << " place with score of " << score[i][1] << endl;
				}
				if (playerSearch == player[i][2])
				{
					cout << setw(12) << "BlackJack: " << i + 1 << " place with score of " << score[i][2] << endl;
				}
			}
			startLoop = false;
		}
}
//function to play the Cup and Balls game
int ballCups(double &cash, int highScore)
{

	char cups[20] = "|1| |2| |3| |4| |5|", startCups[20];
	char *strPtr = cups, *strPtrStart = startCups;
	int cupGuess, cupLocation, holder = 0, cupFinal = 0, count = 0, x = 0;
	
	bool loopEnd = true;

	highScore = 0;
	//game heading
	cout << "\tWelcome to Magic Cups\n"
		 << "All you have to do is pick the right cup 1-5\n"
		 << "then wait and see if the ball appears in that cup\n\n";

	//copies string pointer location from strPtr(cups char array) to strPtrStart(startCups char array)
	strncpy(strPtrStart, strPtr, 20);

	while (loopEnd == true)
	{
		//copies strPtrStart back to strPtr to start new
		strncpy(strPtr, strPtrStart, 20);

		//outputs the cups
		cout << strPtr;

		//sets a random cup location 1-5
		cupLocation = rand() % 5 + 1;

		//declares a char c used to convert cup location into a useable char
		char c = '0' + cupLocation;
		//resets x which is just a loop counter 
		x = 0;
		//searches through cups to find the right char
		while (cups[x] != c)
		{
			x++;
		}

		//writes in the ball based off the x loop counter
		*(strPtr + x) = 'o';


		cout << endl << "The ball is in: " <<cupLocation << endl;//  <---------------------------If you want to cheat uncomment this line to test scoreboard

		//user guesses a cup
		cout << "\nGuess a cup: ";
		cin >> cupGuess;

		//output the pointer to show the location of the ball to user
		cout << "\n";
		cout << strPtr << endl;
		//if statements to declare user a winner or loser
		if (cupGuess == cupLocation)
		{
			cout << "Congratulations you win\n\n";
			cash += 1;
			highScore += 1;
		}
		else if (cupGuess != cupLocation)
		{
			cout << "Sorry you lost\n\n";
			cash -= 1;
			highScore -= 1;
		}
		//calls function to end game loop
		loopEnd = playAgain(cash);
	}
	return highScore;
}
//function to play the War game
int war(double &cash, int highScore)
{
	cards deck[maxCards];
	cards playerCard, dealerCard;
	string card;
	bool loopEnd = true;
	int x = 15;

	highScore = 0;
	//game heading
	cout << "\tWelcome to War\n"
		<< "All you have to do is have the higher card\n";
	//main game while loop  
	while (loopEnd == true)
	{
		//calls functions to create a deck
		createDeck(deck);
		//deals a card to player then prints it
		deal(deck, playerCard);
		cout << "You drew a... \n\t";
		printCard(playerCard);
		cout << endl;
		//deals a card to dealer then prints it
		deal(deck, dealerCard);
		cout << "The Dealers drew a... \n\t";
		printCard(dealerCard);
		cout << endl;
		
		playerCard.card = ACE;           // <------------------------------------------------If you want to cheat uncomment this line to test scoreboard
		
		//Calls winner function to declare a winner then returns the score
		highScore = winner(playerCard.card, dealerCard.card, cash, highScore);

		//calls function to end loop
		loopEnd = playAgain(cash);
	}
	return highScore;
}
//function to play the BlackJack game
int blackJack(double &cash, int highScore)
{
	cards deck[maxCards], playerCard[11], dealerCard[11], temp;
	string hold = " ",stest = "";
	int cardTotal = 0, i = 0, dealerTotal = 0,aceNum = 0;
	bool loopEnd = true;


	highScore = 0;
	//creats a deck of cards
	createDeck(deck);
	//game heading
	cout << "\tWelcome to BlackJack\n"
		 << "Aces are players option and a tie is a draw\n";
	//main loop to keep game running
	while (loopEnd == true)
	{
		//resets variables to restart game
		hold = " ";
		cardTotal = 0;
		dealerTotal = 0;
		//loop to allow player to get more then one card 
		while (cardTotal <= 21 && hold != "no")
		{
			//resets ace variable to 0
			aceNum = 0;
			//deals a player a card
			deal(deck, playerCard[i]);

			//if the card is less then a jack the correct number is added to the total
			if (playerCard[i].card < JACK)
			{
				cardTotal += playerCard[i].card + 2;
			}
			// if the card is a face card 10 is added to the total
			else if (playerCard[i].card > TEN && playerCard[i].card < ACE)
			{
				cardTotal += 10;
			}
			// if an ace will be drawn the player has the option to choose 1 or 11
			else if (playerCard[i].card == ACE)
			{
				cout << "Your next card is an Ace do you want it to be worth 1 or 11: ";
				cin >> aceNum;
				//validates that the ace number is a 1 or 11
				while (aceNum != 1 && aceNum != 11)
				{
					cin.ignore();
					cout << "please enter a 1 or 11: ";
					cin >> aceNum;
				}
				//if user wants ace to be 1, 1 is added
				if (aceNum == 1)
				{
					cardTotal += 1;
				}
				//if user wants ace to be 11, 11 is added
				if (aceNum == 11)
				{
					cardTotal +=  11;
				}
			}
			//Displays card drawn to user
			cout << "You drew a ";
			printCard(playerCard[i]);

			//allows user to stop getting new cards
			if (cardTotal <= 21)
			{
				cout << "\n\tYou have a total of: " << cardTotal << endl
					<< "Do you want another card (yes or no): ";
				cin >> hold;
			}
			//if user goes over 21 they bust and can no longer get cards
			else if (cardTotal > 21)
			{
				cout << "\n\n\tYou Busted with " << cardTotal << endl;
			}

			//loop counter to move card arrays
			i++;
		}
		cout << endl;
		//the dealer will draw cards until they have over 17
		while (dealerTotal < 17)
		{
			//dealer draws a card
			deal(deck, dealerCard[i]);
			//held in a temp slot to output later
			temp = dealerCard[i];

			//if the card is less then a jack the correct number is added to the total
			if (dealerCard[i].card < JACK)
			{
				dealerTotal += dealerCard[i].card + 2;
			}
			// if the card is a face card 10 is added to the total
			else if (dealerCard[i].card > TEN && dealerCard[i].card < ACE)
			{
				dealerTotal += 10;
			}
			// if an ace will be drawn the dealer takes an 11 unless the 11 will make them bust then they get a 1
			else if (dealerCard[i].card == ACE)
			{
				if (dealerTotal < 11)
				{
					dealerTotal += 11;
				}
				else if (dealerTotal >= 11)
				{
					dealerTotal +=  1;
				}
			}
			// output dealer card to player
			cout << "Dealer drew a ";
			printCard(temp);
			cout << "\n\tDealer has a total of: " << dealerTotal << endl;

		}

		cardTotal = 21; //<---------------------------------------------------------uncomment this line if you want to cheat to test scoreboard

		//if neither player bust winner function is used
		if (cardTotal <= 21 && dealerTotal <= 21)
		{
			highScore = winner(cardTotal, dealerTotal, cash, highScore);
		}
		//if dealer bust the player doesn't the player wins
		else if (cardTotal <= 21 && dealerTotal > 21)
		{
			cout << "\n\tCongrats, the dealer busted, you win!\n";
			cash++;
			highScore++;
		}
		//if the player busts and the dealer doesn't the player loses
		else if (cardTotal > 21 && dealerTotal <= 21)
		{
			cout << "\n\tSorry, you busted and lost\n";
			cash--;
			highScore--;
		}
		//if everyone busts the game is a draw
		else if (cardTotal > 21 && dealerTotal > 21)
		{
			cout << "\n\tEveryone Busted, game is a draw\n";
		}

		//function to end the main loop
		loopEnd = playAgain(cash);
	}

	return highScore;
}
void highScore(double score[SIZE][3], string players[SIZE][3], string currentPlayer)
{
	char decision[4], search[SIZE];
	string temp, nameGuess;
	bool endLoop = false;

	// main highscore function while loop 
	while (endLoop != true)
	{
		//Displays the leaderboard headers
		cout << setw(25) << " " << "Top 5 most money made in a sitting\n";

		cout << setw(21) << "Name" << setw(5) << "|" << setw(7) << "Magic Cups" << setw(3) << "|" << setw(12)
			<< "Name" << setw(4) << "|" << setw(5) << "War" << setw(3) << "|" << setw(15)
			<< "Name" << setw(5) << "|" << setw(10) << "BlackJack";
		//Displays the leaderboard names and scores
		for (int i = 0; i < 5; i++)
		{
			cout << "\n";
			int x = 0;
			cout << setw(5) << i + 1 << ":";
			cout << setw(20) << players[i][x] << " ";
			cout << " $" << fixed << setprecision(2) << setw(4) << score[i][x] << " ";
			x = 1;
			cout << setw(20) << players[i][x] << " ";
			cout << " $" << fixed << setprecision(2) << setw(4) << score[i][x] << " ";
			x = 2;
			cout << setw(20) << players[i][x] << " ";
			cout << " $" << fixed << setprecision(2) << setw(4) << score[i][x] << " ";
		}

		//Shows current player if they are available
		showPlayer(score, players, currentPlayer);
		
		//Allows user to keep searching for records until finished
		while (endLoop != true)
		{
			cout << "\nWould you like to search for a player(yes or no): ";
			cin >> decision;
			
			//If user would use any caps this will make all letters lowercase
			for (int i = 0; i < 4; i++)
			{
				decision[i] = tolower(decision[i]);
			}

			//converts decision char array into a temporary string
			temp = decision;
		
			//If statements based off of user choice
			if (temp == "yes")
			{
				//Allows user to search for names
				cout << "Enter the name you want to search: ";
				cin.ignore();
				getline(cin, nameGuess);
				//outputs to the user the data if found
				showPlayer(score, players, nameGuess);
			}
			else if (temp == "no")
			{
				//ends the while loop
				endLoop = true;
			}
			//validates user input
			else
			{
				cout << "\nYou wrote " << temp << " please enter yes or no\n";
			}
			
			
			

		}
	}
}
void playerCashout(Player playerData[SIZE], double &cash, string currentPlayer)
{
	int i = 0;
	
	//If statements to either send a check a bill or do nothing
	if (cash > 0)
	{
		cout << "Thanks for playing a check for $" << cash << " will be sent to\n\n";
	}
	else if (cash < 0)
	{
		cout << "Sorry about your luck but a bill for $" << cash << " will be sent to\n\n";
	}
	else
	{
		cout << "We ended up even no check or bill will be sent, Thanks for playing!\n\n";
	}

	//counter to find the player information
	while (currentPlayer != playerData[i].name)
	{
		i++;
	}

	// If statement to see if player data is needed
	if (cash != 0)
	{
		cout << playerData[i].name << endl
			<< playerData[i].playerInfo.street << endl
			<< playerData[i].playerInfo.city << ", " << playerData[i].playerInfo.state << " " << playerData[i].playerInfo.zip << endl << endl;
		cout << "Your account has been reset to $0.00";
		cash = 0;
	}
}
void scoreSort(double scores[SIZE][3], string names[SIZE][3], int game, string player, int newScore)
{
	int numHolder = 0;
	string strHolder = " ";

	// For loop sorts based off scores
	for (int i = 0; i < SIZE; i++)
	{
		//allows higher scores to be saved
		if (scores[i][game] < newScore)
		{
			//switches the higher score
			numHolder = newScore;
			newScore = scores[i][game];
			scores[i][game] = numHolder;

			//switches name to match score 
			strHolder = player;
			player = names[i][game];
			names[i][game] = strHolder;

		}

	}
	//resets the score
	newScore = 0;
}
int main()
{

	Player players[SIZE];

	int choice = 0, counter = 0, highScoreHolder = 0, gameNum = 0;
	double cash = 0, scores[SIZE][3] = { 8,7,9,7,6,8,6,5,7,3,3,4,2,2,2 };
	bool loopBreak = false;
	string currentPlayer, leaderboardNames[SIZE][3] = { {"Gorden Freeman", "Samus Aran", "Leon Kennedy"},
														{"Master Chief", "Raiden", "Sonic"},
														{"Wario", "Clair Redfield", "Master Chief"},
														{"Samus Aran", "Laura Croft", "Solid Snake"},
														{"Leon Kennedy", "Mario", "Duke Nukem" } };

	//Opening Header 
	cout << "\tWelcome to Ry Guy's Casino" << endl
		<< "Where all games cost $1.00 to play\n"
		<< "In order to save your name to the leaderboard\n"
		<< "and to recieve money. Start with option 1\n";
	
	//main while loop
	while (loopBreak != true)
	{
		//calls and returns the menu choice
		choice = showMenu(choice);
		//resets highscore
		highScoreHolder = 0;

		//main switch that operates the menu
		switch (choice)
		{
			//lets users join so they can be on the leaderboard
		case 1: players[counter] = playerInfo(players, cash, currentPlayer);
			counter++;
			break;

			// To play Magic cups game
		case 2:  highScoreHolder = ballCups(cash, highScoreHolder); 
			// 0 is the first column in the score array
			gameNum = 0;
			
			//sorts to see if you made to high score board
			scoreSort(scores, leaderboardNames, gameNum, currentPlayer, highScoreHolder);
			//resets the high score
			highScoreHolder = 0;
			break;

			// To play War game
		case 3: highScoreHolder = war(cash, highScoreHolder);
			// 1 is the second column in the score array
			gameNum = 1;
			
			//sorts to see if you made to high score board
			scoreSort(scores, leaderboardNames, gameNum, currentPlayer, highScoreHolder);
			//resets the high score
			highScoreHolder = 0;
			break;

			// To play War game
		case 4: highScoreHolder = blackJack(cash, highScoreHolder);
			// 2 is the third column in the score array
			gameNum = 2;
			
			//sorts to see if you made to high score board
			scoreSort(scores, leaderboardNames, gameNum, currentPlayer, highScoreHolder);
			//resets the high score
			highScoreHolder = 0;
			break;

			//To view and search through the high scores
		case 5: highScore(scores, leaderboardNames, currentPlayer);
			break;

			//to send or bill player money
		case 6: playerCashout(players, cash, currentPlayer);
			break;

			//to exit the program
		case 7: loopBreak = true;
			break;

		default:
			cout << "\nPlease Enter a valid Option\n";
			break;
		}
	}

	return 0;
}