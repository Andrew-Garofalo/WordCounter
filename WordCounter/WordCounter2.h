#pragma once
#include <string>

using namespace std;

class WordCounter2
{
private:
	bool programContinue = true;
	int totalNumberWords = 0;
	int totalNumberOfCharacters = 0;
	int runNumber = 1;
	int lengthLargestWord = 0;
	int lengthSmallestWord = 0;
	string lastWord = " ";
	string word;
	string largestWord = " ";
	string smallestWord = " ";
	void setProgramContinue(bool truthValue);
	void addWord(string words);

public:
	WordCounter2();
};

