#include "stdafx.h"
#include "WordCounter2.h"
#include <iostream>
#include <string>

using namespace std;

void WordCounter2::setProgramContinue(bool truthValue)
{
	WordCounter2::programContinue = truthValue;
}

void WordCounter2::addWord(string words)
{
	WordCounter2::totalNumberWords++;
	int wordLength = 0;

	for (int i = 0; i < words.length(); i++)
	{
		wordLength++;
		WordCounter2::totalNumberOfCharacters++;
	}

	if (WordCounter2::runNumber == 1)
	{
		WordCounter2::lengthLargestWord = wordLength;
		WordCounter2::largestWord = words;
	}
	else if (wordLength > WordCounter2::lengthLargestWord)
	{
		WordCounter2::lengthLargestWord = wordLength;
		WordCounter2::largestWord = words;
	}

	if (WordCounter2::runNumber == 1)
	{
		WordCounter2::lengthSmallestWord = wordLength;
		WordCounter2::smallestWord = words;
	}
	else if (wordLength < WordCounter2::lengthSmallestWord)
	{
		WordCounter2::lengthSmallestWord = wordLength;
		WordCounter2::smallestWord = words;
	}
	WordCounter2::runNumber++;
}

WordCounter2::WordCounter2()
{
	cout << "Welcome to the Word Counting Program." << endl;

	while (WordCounter2::programContinue)
	{
		cout << "Please enter a word. (Enter -1 when finished.)" << endl;
		cin >> WordCounter2::word;

		if (WordCounter2::word == "-1")
		{
			setProgramContinue(false);
		}
		else
		{
			WordCounter2::lastWord = word;
			addWord(word);
		}
	}
	cout << endl << "The length of the list is: " << WordCounter2::totalNumberOfCharacters << "." << endl
		<< "The total number of words is: " << WordCounter2::totalNumberWords << "." << endl
		<< "The last word in the list is:" << WordCounter2::lastWord << "." << endl
		<< "The smallest word is: " << WordCounter2::smallestWord << "." << endl
		<< "The longest word is: " << WordCounter2::largestWord << "." << endl;
}
