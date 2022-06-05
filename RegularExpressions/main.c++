#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

void printMenu();
void checkText();

int main()
{
	setlocale(LC_ALL, "Russian");

	// Главные переменные
	string userString = "";

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
			checkText();
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

	cout << "\nВведите [1], чтобы проверить вхождение фразы в текст\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "\nВаш выбор: ";
}

void checkText()
{
	string userPhrase = "";

	cout << "Введите фразу, которая должна содержаться в тексте:";
	getline(cin, userPhrase);

	regex regular(userPhrase);

	cout << "Введите [1], чтобы ввести проверяемый текст с клавиатуры.\n"
		"Введите [2], чтобы проверить текст, содержащийся в файле \"Text.txt\"\n";
	int userChecktypeChose;
	cin >> userChecktypeChose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	
	bool isContains = false;
	switch (userChecktypeChose)
	{
	case 1:
	{
		string textForCheck = "";
		cout << "Введите текст для проверки: ";
		getline(cin, textForCheck);

		regex_iterator<string::iterator> iterator(textForCheck.begin(), textForCheck.end(), regular);
		
		for (regex_iterator<string::iterator> end; iterator != end; iterator++)
		{
			if (iterator->str().empty() == false)
			{
				isContains = true;
				break;
			}
		}
		break;
	}

	case 2:
	{
		std::ifstream file("Text.txt");
		std::string buffer;

		while (!file.eof())
		{
			file >> buffer;
			regex_iterator<string::iterator> iterator(buffer.begin(), buffer.end(), regular);

			for (regex_iterator<string::iterator> end; iterator != end; iterator++)
			{
				if (iterator->str().empty() == false)
				{
					isContains = true;
					break;
				}
			}
		}

		file.close();
		break;
	}
	default:
		cout << "Некоректный ввод!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		break;
	}

	if (isContains)
	{
		cout << "В тексте ";
	}
	else
	{
		cout << "В тексте не ";
	}
	cout << "содержится фраза \"" << userPhrase << "\"\n";
}