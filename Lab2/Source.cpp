#include <iostream>
#include <fstream>
#include <Windows.h>
#include "functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file;
	file.open("BookStorage.txt");
	file.close();

	ChooseOperation();

	cout << "До свидания" << endl;

	system("pause");

	return 0;
}

