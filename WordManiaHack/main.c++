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

	// ������� ����������
	

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

			system("pause");
			break;
		case 2:

			system("pause");
			break;

		case 0:
			cout << "\n�� ��������!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		case 2022:
			cout << "\n���������� :D\n";

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


void printMenu(vector<city>& cities)
{
	cout << "������������ ������ #10 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� - ���������� ���������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";

	cout << "\n������� [], ����� \n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "\n��� �����: ";
}