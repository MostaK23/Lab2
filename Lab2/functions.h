#pragma once
#include <iostream>

void ShowData();//��������� ��� ������ �� ����� �� ����� 
void InputNewData();//������ ����� ������ � ���� 
void AddDataInTheEnd();//�������� ������ � ����� ����� 
void SortDataByAlphabet();//���������� ���� ������ �� �������� (�� ��������) 
void DetermineBookByAuthor();//����������: ���� �� � ���������� ����� ������� ������ 
void FindBiggestBook();//����� ����� � ���������� ����������� ������� 
void FindBookByAuthorAndYear();//����� �������� ���� ������� ������, �������� � ���������� ���� 
int BooksCountByProperty(std::string, std::string);
std::string GetPath();
void ShowOperationList();
void ChooseOperation();