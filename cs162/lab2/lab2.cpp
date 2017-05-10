// Lab2: Anagram Matching
// Javier Rodriguez
// 21 April 2017
// Sources: None

#include <iostream>
#include <string.h>

using namespace std;

//takes a character array and length, then sorts the array alphabetically
void bubbleSort(char list[], int length)
{
	int temp;
	int iteration;
	int index;

	for (iteration = 1; iteration < length; iteration++)
	{
		for(index = 0; index < length - iteration; index++)
			{
				if(list[index] > list[index + 1])
				{
					temp = list[index];
					list[index] = list[index + 1];
					list[index + 1] = temp;
				}
			}
	}
}

// determines if two char arrays are anagrams
int areAnagram(char firstWord[], char secondWord[])
{
	int len1;
	int len2;
	
	// finds the length of the two char arrays
	len1 = strlen(firstWord);
	len2 = strlen(secondWord);
	
	// if the two arrays are the same length, the arrays are sorted alphabetically
	// then the two sorted arrays are compared
	// if the arrays don't match or if the lengths don't match false is returned
	// otherwise true is returned
	if (len1 == len2)
	{
		bubbleSort(firstWord, len1);
		bubbleSort(secondWord, len2);

		for (int i = 0; i < len1; i++)
		{
			if (firstWord[i] != secondWord[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char firstWord[100];
	char secondWord[100];
	char response = 'y';
	
	//prompts user to select to compare two words
	while(response == 'y' || response == 'Y')
	{
		cout << "Enter the first word:" << endl;
		cin >> firstWord;
		cout << "\nEnter the second word:" << endl;
		cin >> secondWord;

		// calls function areAnagram to determine if two words entered are anagrams of eachother
		// if they are, the user is notified that they are anagrams
		// if they are not, the user is notified that they are not anagrams
		if(areAnagram(firstWord, secondWord))
		{
			cout << "The words are anagrams of eachother." << endl;
		}

		else
		{
			cout << "The words are NOT anagrams of eachother." << endl;
		}
	
		cout << "Do you want to continue? (y or n)" << endl;
		cin >> response;
	}
	
	return 0;
}
