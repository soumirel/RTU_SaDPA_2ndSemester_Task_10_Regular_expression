#include "Trie.h"
#include "StringEncoder.h"

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void printMenu();
void wordsManiaTraversal(size_t trieCell, size_t currentPosition, bool checkedCells[], string gamefield, string resultWord);
void WordsmaniaCheat(string& gamefield);
bool stringComparator(string firstS, string secondS);
void printHackResult();


Trie mainTrie;
StringEncoder encoder;
set<string> Res;
vector<string> Output;

int main()
{
	//setlocale(LC_ALL, "Russian");
	mainTrie.loadDictionary("Dictonary.txt");

	// Главные переменные
	string gamefield = "";

	//Переменные для пользовательского выбора.
	int userMenuChoice = -1;
	

	// Главный меню-цикл.
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
			encoder.encodeString(gamefield, encoder.ConsoleSample);
			WordsmaniaCheat(gamefield);
			printHackResult();
			system("pause");
			break;

		case 0:
			cout << "\nДо свидания!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		default:
			cout << "\nЯ не понимаю вас.\n";
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
	cout << "Практическая работа #10 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание - Регулярные выражения.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";

	cout << "\nВведите [], чтобы \n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "\nВаш выбор: ";
}


void wordsManiaTraversal(size_t trieCell, size_t currentPosition, bool checkedCells[], string gamefield, string resultWord)
{
	bool bannedWays[11] = { false };

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
		if (bannedWays[i + 5])
		{
			continue;
		}

		int nextPosition = currentPosition + i;

		if (!checkedCells[nextPosition]) 
		{
			if (mainTrie.trie[trieCell].child[gamefield[nextPosition]] != 0) 
			{
				checkedCells[nextPosition] = true;

				wordsManiaTraversal(mainTrie.trie[trieCell].child[gamefield[nextPosition]],
					nextPosition, checkedCells, gamefield, resultWord + gamefield[nextPosition]);

				checkedCells[nextPosition] = false;
			}
		}

		if (mainTrie.trie[trieCell].isLeaf) 
		{
			Res.insert(resultWord);
		}
	}
}


void WordsmaniaCheat(string& gamefield)
{
	bool checkedCells[16] = { false };
	for (size_t i = 0; i < 16; i++) 
	{
		if (mainTrie.trie[0].child[gamefield[i]] != 0)
		{
			checkedCells[i] = true;
			wordsManiaTraversal(mainTrie.trie[0].child[gamefield[i]], i,
				checkedCells, gamefield, gamefield.substr(i, 1));
			checkedCells[i] = false;
		}
	}
}


void printHackResult()
{
	for (auto& token : Res) 
	{
		Output.push_back(token);
	}
	Res.clear();

	sort(Output.begin(), Output.end(), stringComparator);
	for (auto& token : Output) 
	{
		for (auto& tokenOfToken : token)
		{
			cout << encoder.ConsoleSample[tokenOfToken];
		}
		cout << endl;
	}
	cout << "==================" << endl << endl;
	Output.clear();
}


bool stringComparator(string firstS, string secondS)
{
	if (firstS.size() >= secondS.size()) 
	{
		return false;
	}
	else return true;
}