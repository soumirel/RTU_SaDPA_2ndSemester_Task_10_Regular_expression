#include "Trie.h"
#include "StringEncoder.h"

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void printMenu();
void wordsManiaTraversal(size_t currentPosition, size_t trieCell, bool checkedCells[], string gamefield, string resultWord);
void WordsmaniaCheat(string gamefield);
bool cmp(string A, string B);
void printHackResult();


Trie mainTrie;
StringEncoder encoder;
set<string> Res;
vector<string> Output;

int main()
{
	//setlocale(LC_ALL, "Russian");
	mainTrie.loadDictionary("Dictonary.txt");

	// ������� ����������
	string gamefield = "";

	//���������� ��� ����������������� ������.
	int userMenuChoice = -1;
	

	// ������� ����-����.
	while (userMenuChoice != 0)
	{
		system("cls");
		printMenu();

		cin >> userMenuChoice;
		cin.ignore();

		switch (userMenuChoice)
		{
		case 1:
			cin >> gamefield;
			WordsmaniaCheat(encoder.encodeString(gamefield, encoder.ConsoleSample));
			printHackResult();
			system("pause");
			break;

		case 0:
			cout << "\n�� ��������!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		default:
			cout << "\n� �� ������� ���.\n";
			cin.clear();

			cout << '\n';
			system("pause");
			break;
		}
	}

	return 0;
}


void printMenu()
{
	cout << "������������ ������ #10 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� - ���������� ���������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";

	cout << "\n������� [], ����� \n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "\n��� �����: ";
}


void wordsManiaTraversal(size_t currentPosition, size_t trieCell, bool checkedCells[], string gamefield, string resultWord)
{
	bool bannedWays[11] = { false };

	//������ �� ���� � ����� -2, 2 � � ���� ����.
	for (int i = -2; i <= 2; i += 2)
	{
		bannedWays[i + 5] = true;
	}

	if (currentPosition % 4 == 0)
	{
		for (int i = -5; i <= 3; i += 4)
		{
			bannedWays[i + 5] = true;
		}
	}

	if (currentPosition < 4)
	{
		for (int i = -5; i <= -3; i++)
		{
			bannedWays[i + 5] = true;
		}
	}

	if (currentPosition % 4 == 3)
	{
		for (int i = -3; i <= 5; i += 4)
		{
			bannedWays[i + 5] = true;
		}
	}

	if (currentPosition >= 12)
	{
		for (int i = 3; i <= 5; i++)
		{
			bannedWays[i + 5] = true;
		}
	}

	for (int i = -5; i <= 5; i++)
	{
		int nextPosition = currentPosition + i;
		if (bannedWays[i + 5] == true)
		{
			continue;
		}
		if (!checkedCells[nextPosition])
		{
			if (mainTrie.trie[trieCell].child[gamefield[nextPosition]] != 0) {
				checkedCells[nextPosition] = true;
				wordsManiaTraversal(nextPosition, mainTrie.trie[trieCell].child[gamefield[nextPosition]],
					checkedCells, gamefield, resultWord + gamefield[currentPosition]);
				checkedCells[nextPosition] = false;
			}
		}
		if (mainTrie.trie[trieCell].isLeaf) {
			Res.insert(resultWord);
		}
	}
}


void WordsmaniaCheat(string gamefield)
{
	bool checkedCells[16] = { false };
	for (size_t i = 0; i < 16; i++) {
		if (mainTrie.trie[0].child[gamefield[i]] != 0)
		{
			checkedCells[i] = true;
			wordsManiaTraversal(i, mainTrie.trie[0].child[gamefield[i]],
				checkedCells, gamefield, "");
			checkedCells[i] = false;
		}
	}
}


void printHackResult()
{
	for (auto& token : Res) {
		Output.push_back(token);
	}
	Res.clear();

	sort(Output.begin(), Output.end(), cmp);
	for (auto i(Output.begin()); i != Output.end(); ++i) {
		for (auto j((*i).begin()); j != (*i).end(); ++j) {
			cout << encoder.ConsoleSample[*j];
		}
		cout << endl;
	}
	cout << "==================" << endl << endl;
	Output.clear();
}


bool cmp(string A, string B) {
	if (A.size() >= B.size()) {
		return false;
	}
	else return true;
}