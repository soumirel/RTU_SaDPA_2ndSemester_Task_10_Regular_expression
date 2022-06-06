#pragma once

#include <vector>

template <typename T>
class Trie
{
private:

	template<typename T>
	struct Node
	{
		T data;
		std::vector<Node*> child;
		bool isLeaf;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node<T> nullNode = Node<T>(NULL);

	void addNode(T newData);

public:
	template<typename T>
	Trie();

	std::vector<Node> trie;

	void addNewBranch(T newBranch);

};

