#include "Trie.h"
#include <iostream>

Trie::Trie()
{
	trie.push_back(nullNode);
}

void Trie::loadDictionary(std::string fileName)
{
	std::ifstream file(fileName);
	std::string buffer;

	while (!file.eof())
	{
		file >> buffer;
		addWord(encodeString(buffer, FstreamSample));
	}

	file.close();

}

void Trie::addWord(std::string S)
{

	size_t currentNode = 0;
	for (auto& vectorToken : S)
	{

		if (trie.at(currentNode).child[vectorToken] == 0)
		{
			trie.push_back(nullNode);
			trie.at(currentNode).child[vectorToken] = trie.size() - 1;
			currentNode = trie.size() - 1;
		}
		else
		{
			currentNode = trie.at(currentNode).child[vectorToken];
		}
	}
	trie.at(currentNode).isLeaf = true;
}
