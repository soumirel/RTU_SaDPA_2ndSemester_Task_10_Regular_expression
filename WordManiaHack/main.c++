#include <iostream>
#include <string>
#include <vector>
#include <ctime>  

#include "Timer.h"

using namespace std;

void printMenu();

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	// Главные переменные
	

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

			system("pause");
			break;
		case 2:

			system("pause");
			break;

		case 0:
			cout << "\nДо свидания!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		case 2022:
			cout << "\nПасхалочка :D\n";

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


void printMenu(vector<city>& cities)
{
	cout << "Практическая работа #10 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание - Регулярные выражения.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";

	cout << "\nВведите [], чтобы \n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "\nВаш выбор: ";
}