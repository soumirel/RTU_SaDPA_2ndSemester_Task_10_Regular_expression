#include "Trie.h"
#include <iostream>

Trie::Trie()
{
	trie.push_back(nullNode);
}

void Trie::loadDictionary(std::string fileName)
{
	StringEncoder encoder;

	std::ifstream file(fileName);
	std::string buffer;

	while (!file.eof())
	{
		file >> buffer;
		encoder.encodeString(buffer, encoder.FstreamSample);
		addWord(buffer);
	}

	file.close();

}

void Trie::addWord(std::string S)
{
	size_t currentNode = 0;

	for (auto& token : S)
	{

		if (trie.at(currentNode).child[token] == 0)
		{
			trie.push_back(nullNode);
			trie.at(currentNode).child[token] = trie.size() - 1;
			currentNode = trie.size() - 1;
		}
		else
		{
			currentNode = trie.at(currentNode).child[token];
		}
	}
	trie.at(currentNode).isLeaf = true;
}
