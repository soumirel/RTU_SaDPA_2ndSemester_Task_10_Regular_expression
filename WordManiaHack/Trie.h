#pragma once

#include "StringEncoder.h"

#include <vector>
#include <string>
#include <fstream>


class Trie :
	public StringEncoder
{
private:
	struct Node
	{
		size_t child[ALPHABET_SIZE];
		bool isLeaf;
	};

	Node nullNode = { NULL };

	void addWord(std::string S);

public:
	Trie();

	std::vector<Node> trie;

	void loadDictionary(std::string fileName);

	
	
};

