#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

static int bookStorageSize = 0;

void ShowOperationList()
{
	cout << "�������� ����� ��������:" << endl;
	cout << "|1|��������� ��� ������ �� ����� �� �����" << endl;
	cout << "|2|������ ����� ������ � ����" << endl;
	cout << "|3|�������� ������ � ����� �����" << endl;
	cout << "|4|���������� ���� ������ �� �������� (�� ��������)" << endl;
	cout << "|5|����������: ���� �� � ���������� ����� ������� ������" << endl;
	cout << "|6|����� ����� � ���������� ����������� �������" << endl;
	cout << "|7|����� �������� ���� ������� ������, �������� � ���������� ����" << endl;
	cout << "|0|����� �� ���������" << endl;
	cout << "��� �����:" << endl;
}


string GetPath()
{
	string path;
	cout << "������� ��� �����(BookStorage)" << endl;
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
		bookStorageSize = BooksCountByProperty("BookStorage.txt", "�����: ");
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
			cout << "����� �������� ���" << endl;
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
		cout << "�� ������� ������� ����" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}

struct Book
{
	string author;//�����
	string title;//��������
	string publicationYear;//��� ����������
	string publishingHouse;//������������
	string pageNumber;//���������� �������
};

void InputNewData()
{
	string path = GetPath();

	ofstream file;

	file.open(path, ios::out | ios::_Nocreate);

	if (file)
	{
		Book book;

		cout << "������� ������: ";
		cin.get();
		getline(cin, book.author);
		file << "�����: " << book.author << "\n";

		cout << "������� �������� �����: ";
		getline(cin, book.title);
		file << "��������: " << book.title << "\n";

		cout << "������� ��� ����������: ";
		cin >> book.publicationYear;
		file << "����������: " << book.publicationYear << "\n";

		cout << "������� ��� ������������: ";
		cin.get();
		getline(cin, book.publishingHouse);
		file << "������������: " << book.publishingHouse << "\n";

		cout << "������� ���������� �������: ";
		cin >> book.pageNumber;
		file << "��������: " << book.pageNumber << "\n";

		file << "\n";
	}
	else
	{
		cout << "���� �� ������" << endl;
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

		cout << "������� ������: ";
		cin.get();
		getline(cin, book.author);
		file << "�����: " << book.author << "\n";

		cout << "������� �������� �����: ";
		getline(cin, book.title);
		file << "��������: " << book.title << "\n";

		cout << "������� ��� ����������: ";
		cin >> book.publicationYear;
		file << "����������: " << book.publicationYear << "\n";

		cout << "������� ��� ������������: ";
		cin.get();
		getline(cin, book.publishingHouse);
		file << "������������: " << book.publishingHouse << "\n";

		cout << "������� ���������� �������: ";
		cin >> book.pageNumber;
		file << "��������: " << book.pageNumber << "\n";

		file << "\n";
	}
	else
	{
		cout << "���� �� ������" << endl;
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
		_property = "�����: ";
		break;
	case 2:
		_property = "��������: ";
		break;
	case 3:
		_property = "����������: ";
		break;
	case 4:
		_property = "������������: ";
		break;
	case 5:
		_property = "��������: ";
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

		//����������
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
			fout << "�����: " << books[i].author << '\n';
			fout << "��������: " << books[i].title << '\n';
			fout << "����������: " << books[i].publicationYear << '\n';
			fout << "������������: " << books[i].publishingHouse << '\n';
			fout << "��������: " << books[i].pageNumber << '\n';
			fout << endl;
		}

		fout.close();

		delete[] books;
	}
	else
	{
		cout << "�� ������� ������� ����" << endl;
	}



	system("pause");
	system("cls");
}

int BooksCountByProperty(string path, string propertyName) //���������� ����
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
		cout << "�� ������� ������� ����" << endl;
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
			string name = "�����: ";

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

		cout << "������� ��� ������: ";
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
			cout << "����� ����� ����." << endl;
		}
		else
		{
			cout << "������ ������ ���." << endl;
		}

		delete[] books;
	}
	else
	{
		cout << "�� ������� ������� ����" << endl;
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

		cout << "����� � ���������� ����������� �������: " << books[index].title << endl;
		cout << "���������� ������� � ���: " << books[index].pageNumber << endl;

		delete[] books;
	}
	else
	{
		cout << "�� ������� ������� ����" << endl;
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
		cout << "������� ������ ";
		cin >> findingAuthor;

		string currentYear;
		cout << "������� ��� ������� ";
		cin >> currentYear;

		bool isExist = false;

		for (int i = 0; i < bookStorageSize; i++)
		{
			if (findingAuthor == books[i].author && books[i].publicationYear >= currentYear)
			{
				cout << "===================================" << endl;
				cout << "�����: " << books[i].title << endl;
				cout << "�����: " << books[i].author << endl;
				cout << "���: " << books[i].publicationYear << endl;
				isExist = true;
			}
		}

		if (!isExist)
		{
			cout << "���� ��������������� �������� ���." << endl;
		}
	}
	else
	{
		cout << "�� ������� ������� ����" << endl;
	}

	file.close();

	system("pause");
	system("cls");
}