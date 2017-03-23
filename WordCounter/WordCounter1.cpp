#include "stdafx.h"
#include "WordCounter1.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


WordCounter1::WordCounter1()
{
	cout << "Welcome to the Word Counting Program." << endl;

	while (WordCounter1::gameContinue)
	{
		cout << "Please enter a word. (Enter -1 when finished.)" << endl;
		cin >> WordCounter1::word;

		if (WordCounter1::word == "-1")
		{
			setGameContinue(false);
		}
		else
		{
			addWord(word);
		}
	}

	int response = 0;
	setGameContinue(true);

	while (WordCounter1::gameContinue)
	{
		cout << endl << "If you would like to add a word, press (1)." << endl
			<< "To get the total number of words in the list, press (2)." << endl
			<< "To retrieve the last word entered, press (3)." << endl
			<< "To get the total number of letters entered, press (4)." << endl
			<< "To get the average number of letters versus the number of words, press (5)." << endl
			<< "To get the smallest word that was entered, press (6)." << endl
			<< "To get the longest word that was entered, press (7)." << endl
			<< "To exit the program, press (8)." << endl;

		cin >> response;

		switch (response)
		{
		case 1:
			cout << endl << "What word would you like to add?" << endl;
			cin >> WordCounter1::word;

			addWord(word);
			break;
		case 2:
			cout << getSize() << endl;

			break;
		case 3:
			cout << lastWord() << endl;

			break;
		case 4:
			cout << totalCharacters() << endl;

			break;
		case 5:
			cout << setprecision(2) << fixed << averageCharacters() << endl;

			break;
		case 6:
			cout << smallestWord() << endl;

			break;
		case 7:
			cout << longestWord() << endl;

			break;
		case 8:
			setGameContinue(false);
			break;
		default:
			cout << "You have entered an invalid number, please try again." << endl;
		}
	}
}

// Add a the next word to the vector
void WordCounter1::addWord(string word)
{
	WordCounter1::words.push_back(word);
}

// set to true to continue program, false to end.
void WordCounter1::setGameContinue(bool truthValue)
{
	WordCounter1::gameContinue = truthValue;
}

// returns number of words entered so far
int WordCounter1::getSize()
{
	return WordCounter1::words.size();
}

// returns the most recent entered word
string WordCounter1::lastWord()
{
	return WordCounter1::words.at(getSize() - 1);
}

// returns the total characters in the words that have been entered
int WordCounter1::totalCharacters()
{
	int numberCharacters = 0;

	// go through each word
	for (int i = 0; i < WordCounter1::words.size(); i++)
	{
		string word = WordCounter1::words.at(i);
		
		// go through each letter in each word
		for (int j = 0; j < word.length(); j++)
		{
			numberCharacters++;
		}
	}

	return numberCharacters;
}

// returns the average number of characters in the vector
double WordCounter1::averageCharacters()
{
	return static_cast<double>(totalCharacters()) / WordCounter1::words.size();
}

// returns the smallest word entered so far
string WordCounter1::smallestWord()
{
	string shortestWord = " ";

	// go through each word entered
	for (int i = 0; i < WordCounter1::words.size(); i++)
	{
		int numberCharacters = 0;
		string word = WordCounter1::words.at(i);

		// iterate through letters of each word
		for (int j = 0; j < word.length(); j++)
		{
			numberCharacters++;
		}

		// if current word is the shortest encountered, make it the shortest word.
		if (i == 0)
		{
			shortestWord = WordCounter1::words.at(i);
		}
		else if (numberCharacters < shortestWord.size())
		{
			shortestWord = WordCounter1::words.at(i);
		}
	}

	return shortestWord;
}

string WordCounter1::longestWord()
{

	string longestWord = " ";

	// go through each word
	for (int i = 0; i < WordCounter1::words.size(); i++)
	{
		int numberCharacters = 0;
		string word = WordCounter1::words.at(i);

		// iterate through letters of each word
		for (int j = 0; j < word.length(); j++)
		{
			numberCharacters++;
		}

		// if current word is the shortest encountered, make it the shortest word.
		if (i == 0)
		{
			longestWord = WordCounter1::words.at(i);
		}
		else if (numberCharacters > longestWord.size())
		{
			longestWord = WordCounter1::words.at(i);
		}
	}

	return longestWord;
}
