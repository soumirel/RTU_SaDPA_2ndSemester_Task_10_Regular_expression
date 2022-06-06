#include <iostream>
#include "Test.h"
#include <random>

using namespace std;

string generateString(size_t wordLen);

int main()
{
	srand(time(0));

	Test newTrie;

	vector<string> words;

	size_t wordLen = 100000;

	for (size_t i = 0; i < 100; i++)
	{
		words.push_back(generateString(wordLen));
	}

	for (size_t i = 0; i < 100; i++)
	{
		newTrie.addNewBranch(words.at(i));
	}

	size_t randomIndex = 0 + rand() % 100;

	cout << newTrie.isInTrie(words.at(randomIndex));

	return 0;
}

string generateString(size_t wordLen)
{
	string resultString = "";

	for (size_t i = 0; i < wordLen; i++)
	{
		resultString += char(65 + rand() % (90 - 65 + 1));
	}

	return resultString;
}