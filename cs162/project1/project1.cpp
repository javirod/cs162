// Project 1: Dice Game
// Javier Rodriguez
// 09 April 2017
// Sources: None

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

int main()
{
	char response = 'y';
	string name;
	int die1;		//value of first die
	int die2;		//value of second die
	int sum = 0;		//sum of die1 and die2
	int score = 0;		//total score of player
	int rolls = 0;		//number of rolls since last game begun

	cout << "\n\n&&&&& SIMPLE DICE GAME &&&&&" << endl;	

	//Prompts user for name
	cout << "What is your name? ";
	cin >> name;
	cout << "\n";

	srand((unsigned) time(0)); // Seeding the Library

	while (response == 'y' || response == 'Y')
	{
		while (rolls < 5)
		{
			cout << "Rolling dice..." << endl;
			sleep(1);	//this will pause for 1 second
			die1 = (rand() % 6) + 1;
			die2 = (rand() % 6) + 1;
			sum = die1 + die2;

			cout << name << ", you rolled a " << die1 << " and a " << die2 << endl;
			cout << "For a total of \n" << sum << endl;

			//user wins game
			if (sum == 7 || sum == 11)
			{
				score += 3;
				cout << name << " WINS! three points earned\n" << endl;
				rolls = 0;
				break;
			}

			//user loses game
			else if (sum == 2 || sum == 3 || sum == 12)
			{
				cout << name << " lost the game. no points.\n" << endl;
				rolls = 0;
				break;
			}
			//all other sums causes dice to be rolled again
			else
			{
				rolls++;
				//checks whether 5 re-rolls have been made
				//if so, then a point is awarded and the counter
				//reinitialized
				if (rolls ==  5)
				{
					score += 1;
					rolls = 0;
					cout << name << " draws. one point earned.\n" << endl;
					break;
				}
				cout << "re-roll dice.\n" << endl;
			}
		}
		cout << "\n+++ END GAME +++" << endl;
		cout << name << " do you want to play again? (y or n)" << endl;
		cin >> response;
		cout << "\n";
	}
	
	cout << name << "'s total score is: " << score << "\nGOODBYE!\n\n";

	return 0;
}
