#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

static int bookStorageSize = 0;

void ShowOperationList()
{
	cout << "Выберите номер действия:" << endl;
	cout << "|1|Загрузить все данные из файла на экран" << endl;
	cout << "|2|Ввести новые данные в файл" << endl;
	cout << "|3|Добавить данные в конец файла" << endl;
	cout << "|4|Сортировка базы данных по алфавиту (по названию)" << endl;
	cout << "|5|Определить: есть ли в библиотеке книги данного автора" << endl;
	cout << "|6|Найти книгу с наибольшим количеством страниц" << endl;
	cout << "|7|Найти названия книг данного автора, изданных с указанного года" << endl;
	cout << "|0|Выход из программы" << endl;
	cout << "Ваш выбор:" << endl;
}


string GetPath()
{
	string path;
	cout << "Введите имя файла(BookStorage)" << endl;
	cin >> path;
	path += ".txt";
	cout << endl;
	return path;
}

void ChooseOperation()
{
	int n;
	bool inProcess = true;

	while (inProcess)
	{
		ShowOperationList();
		bookStorageSize = BooksCountByProperty("BookStorage.txt", "Автор: ");
		cin >> n;
		switch (n)
		{
		case 1:
			ShowData();
			break;
		case 2:
			InputNewData();
			break;
		case 3:
			AddDataInTheEnd();
			break;
		case 4:
			SortDataByAlphabet();
			break;
		case 5:
			DetermineBookByAuthor();
			break;
		case 6:
			FindBiggestBook();
			break;
		case 7:
			FindBookByAuthorAndYear();
			break;
		case 0:
			inProcess = false;
			break;
		default:
			cout << "Такой операции нет" << endl;
			break;
		}
	}
}

void ShowData()
{
	ifstream file;

	string path = GetPath();

	file.open(path, ios::in);

	if (file)
	{
		while (file)
		{
			string text;
			getline(file, text);
			cout << text << endl;
		}
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}

struct Book
{
	string author;//Автор
	string title;//Название
	string publicationYear;//Год публикации
	string publishingHouse;//Издательство
	string pageNumber;//Количество страниц
};

void InputNewData()
{
	string path = GetPath();

	ofstream file;

	file.open(path, ios::out | ios::_Nocreate);

	if (file)
	{
		Book book;

		cout << "Введите автора: ";
		cin.get();
		getline(cin, book.author);
		file << "Автор: " << book.author << "\n";

		cout << "Введите название книги: ";
		getline(cin, book.title);
		file << "Название: " << book.title << "\n";

		cout << "Введите год публикации: ";
		cin >> book.publicationYear;
		file << "Публикация: " << book.publicationYear << "\n";

		cout << "Введите имя издательства: ";
		cin.get();
		getline(cin, book.publishingHouse);
		file << "Издательство: " << book.publishingHouse << "\n";

		cout << "Введите количество страниц: ";
		cin >> book.pageNumber;
		file << "Страницы: " << book.pageNumber << "\n";

		file << "\n";
	}
	else
	{
		cout << "Файл не найден" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}

void AddDataInTheEnd()
{
	ofstream file;

	string path = GetPath();

	file.open(path, ios::app | ios::_Nocreate);

	if (file)
	{
		Book book;

		cout << "Введите автора: ";
		cin.get();
		getline(cin, book.author);
		file << "Автор: " << book.author << "\n";

		cout << "Введите название книги: ";
		getline(cin, book.title);
		file << "Название: " << book.title << "\n";

		cout << "Введите год публикации: ";
		cin >> book.publicationYear;
		file << "Публикация: " << book.publicationYear << "\n";

		cout << "Введите имя издательства: ";
		cin.get();
		getline(cin, book.publishingHouse);
		file << "Издательство: " << book.publishingHouse << "\n";

		cout << "Введите количество страниц: ";
		cin >> book.pageNumber;
		file << "Страницы: " << book.pageNumber << "\n";

		file << "\n";
	}
	else
	{
		cout << "Файл не найден" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}

void FillStruct(Book*& books, int& structPosition, string text, int propertyNumber)
{
	int position = 0;

	string _property = "";

	switch (propertyNumber)
	{
	case 1:
		_property = "Автор: ";
		break;
	case 2:
		_property = "Название: ";
		break;
	case 3:
		_property = "Публикация: ";
		break;
	case 4:
		_property = "Издательство: ";
		break;
	case 5:
		_property = "Страницы: ";
		break;
	}

	for (int i = 0; i < text.length(); i++)
	{
		if (position == _property.length())
		{
			string propertyName = text.substr(i);

			switch (propertyNumber)
			{
			case 1:
				books[structPosition].author = propertyName;
				break;
			case 2:
				books[structPosition].title = propertyName;
				break;
			case 3:
				books[structPosition].publicationYear = propertyName;
				break;
			case 4:
				books[structPosition].publishingHouse = propertyName;
				break;
			case 5:
				books[structPosition].pageNumber = propertyName;
				structPosition++;
				break;
			}
		}

		if (text[i] == _property[position])
		{
			position++;
		}
		else
		{
			position = 0;
		}
	}
}

void SortDataByAlphabet()
{
	ifstream file;

	string path = "BookStorage.txt";

	cout << endl;

	file.open(path, ios::in);

	if (file)
	{
		Book* books = new Book[bookStorageSize];

		int positionInArray = 0;

		while (file)
		{
			string text;
			getline(file, text);

			for (int n = 1; n <= 5; n++)
			{
				FillStruct(books, positionInArray, text, n);
			}
		}
		file.close();

		//Сортировка
		for (int i = 1; i < bookStorageSize; i++)
		{
			for (int j = 0; j < bookStorageSize - i; j++)
			{
				if (books[j].title > books[j + 1].title)
				{
					swap(books[j].author, books[j + 1].author);
					swap(books[j].pageNumber, books[j + 1].pageNumber);
					swap(books[j].publicationYear, books[j + 1].publicationYear);
					swap(books[j].publishingHouse, books[j + 1].publishingHouse);
					swap(books[j].title, books[j + 1].title);
				}
			}
		}

		ofstream fout;
		fout.open(path, ios::out);

		for (int i = 0; i < bookStorageSize; i++)
		{
			fout << "Автор: " << books[i].author << '\n';
			fout << "Название: " << books[i].title << '\n';
			fout << "Публикация: " << books[i].publicationYear << '\n';
			fout << "Издательство: " << books[i].publishingHouse << '\n';
			fout << "Страницы: " << books[i].pageNumber << '\n';
			fout << endl;
		}

		fout.close();

		delete[] books;
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}



	system("pause");
	system("cls");
}

int BooksCountByProperty(string path, string propertyName) //Количество книг
{
	ifstream file;

	file.open(path, ios::in);

	if (file)
	{
		string text;
		int amount = 0;

		while (file)
		{
			getline(file, text);

			int position = 0;

			for (int i = 0; i < text.length() + 1; i++)
			{
				if (position == propertyName.length())
				{
					amount++;
					position = 0;
				}

				if (text[i] == propertyName[position])
				{
					position++;
				}
				else
				{
					position = 0;
				}
			}
		}
		file.close();

		return amount;
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
		return 0;
	}
}

void DetermineBookByAuthor()
{
	ifstream file;

	string path = GetPath();

	cout << endl;

	file.open(path, ios::in);

	if (file)
	{
		Book* books = new Book[bookStorageSize];

		int positionInArray = 0;

		while (file)
		{
			string text;
			string name = "Автор: ";

			getline(file, text);

			int position = 0;

			for (int i = 0; i < text.length(); i++)
			{
				if (position == name.length())
				{
					string authorName = text.substr(i);

					books[positionInArray].author = authorName;
					positionInArray++;

					position = 0;
				}

				if (text[i] == name[position])
				{
					position++;
				}
				else
				{
					break;
				}
			}
		}

		string foundingAuthor;
		bool authorExists = false;

		cout << "Введите имя автора: ";
		cin.get();
		getline(cin, foundingAuthor);

		for (int i = 0; i < bookStorageSize; i++)
		{
			if (books[i].author == foundingAuthor)
			{
				authorExists = true;
				break;
			}
		}

		if (authorExists)
		{
			cout << "Такой автор есть." << endl;
		}
		else
		{
			cout << "Такого автора нет." << endl;
		}

		delete[] books;
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}

	system("pause");
	system("cls");

	file.close();
}

void FindBiggestBook()
{
	ifstream file;

	string path = "BookStorage.txt";

	file.open(path, ios::in);

	if (file)
	{
		string text;

		Book* books = new Book[bookStorageSize];

		int positionInArray = 0;

		while (file)
		{
			getline(file, text);

			for (int n = 1; n <= 5; n++)
			{
				FillStruct(books, positionInArray, text, n);
			}
		}

		int index = 0;

		string max = books[0].pageNumber;

		for (int i = 1; i < bookStorageSize; i++)
		{
			if (books[i].pageNumber > books[i - 1].pageNumber)
			{
				max = books[i].pageNumber;
				index = i;
			}
		}

		cout << "Книга с наибольшим количеством страниц: " << books[index].title << endl;
		cout << "Количество страниц в ней: " << books[index].pageNumber << endl;

		delete[] books;
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}

void FindBookByAuthorAndYear()
{
	ifstream file;

	string path = "BookStorage.txt";

	file.open(path, ios::in);

	if (file)
	{
		Book* books = new Book[bookStorageSize];

		string text;

		int positionInArray = 0;

		while (file)
		{
			getline(file, text);

			for (int n = 1; n <= 5; n++)
			{
				FillStruct(books, positionInArray, text, n);
			}
		}

		string findingAuthor;
		cout << "Введите автора ";
		cin >> findingAuthor;

		string currentYear;
		cout << "Введите год издания ";
		cin >> currentYear;

		bool isExist = false;

		for (int i = 0; i < bookStorageSize; i++)
		{
			if (findingAuthor == books[i].author && books[i].publicationYear >= currentYear)
			{
				cout << "===================================" << endl;
				cout << "Книга: " << books[i].title << endl;
				cout << "Автор: " << books[i].author << endl;
				cout << "Год: " << books[i].publicationYear << endl;
				isExist = true;
			}
		}

		if (!isExist)
		{
			cout << "Книг удовлетворяющих условиям нет." << endl;
		}
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}