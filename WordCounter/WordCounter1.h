#pragma once
#include <vector>
#include <string>

using namespace std;

class WordCounter1
{
private:
	bool gameContinue = true;
	int size = 0;
	string word;
	vector<string> words;
	void addWord(string word);
	void setGameContinue(bool truthValue);
	int getSize();
	string lastWord();
	int totalCharacters();
	double averageCharacters();
	string smallestWord();
	string longestWord();

public:
	WordCounter1();
};

