#include "Test.h"
#include <iostream>

Test::Test(char data)
{
	this->data = data;
}

void Test::addNewBranch(std::string newBranch)
{
	Test* currentNode = this;
	bool isMoveDeeper = false;

	for (size_t i = 0; i < newBranch.size(); i++)
	{
		for (auto& currentChild : currentNode->children)
		{
			if (currentChild->data == newBranch.at(i))
			{
				currentNode = currentChild;
				i++;
				break;
			}
		}

		Test* newChild = new Test(newBranch.at(i));
		currentNode->children.push_back(newChild);
		currentNode = newChild;
	}


}

bool Test::isInTrie(std::string word)
{
	Timer newTimer;
	Test* currentNode = this;
	bool isMoveDeeper;

	size_t iterator = 0;

	for (auto newBranchToken : word)
	{
		isMoveDeeper = false;

		for (auto& currentChild : currentNode->children)
		{
			iterator++;
			if (currentChild->data == newBranchToken && currentChild)
			{
				currentNode = currentChild;
				isMoveDeeper = true;
				break;
			}
		}

		iterator++;
		if (isMoveDeeper == false)
		{
			std::cout << "The number of operations = " << iterator << '\n';
			return false;
		}
	}

	std::cout << "The number of operations = " << iterator << '\n';
	return true;
}
