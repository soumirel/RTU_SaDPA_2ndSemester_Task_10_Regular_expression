#pragma once

#include "Timer.h"

#include <vector>
#include <string>

class Test
{
private:
	char data;
	std::vector<Test*> children;

public:
	Test(char data = 0);

	void addNewBranch(std::string newBranch);

	bool isInTrie(std::string word);
};

