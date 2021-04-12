#pragma once
#include <iostream>

void ShowData();//Загрузить все данные из файла на экран 
void InputNewData();//Ввести новые данные в файл 
void AddDataInTheEnd();//Добавить данные в конец файла 
void SortDataByAlphabet();//Сортировка базы данных по алфавиту (по названию) 
void DetermineBookByAuthor();//Определить: есть ли в библиотеке книги данного автора 
void FindBiggestBook();//Найти книгу с наибольшим количеством страниц 
void FindBookByAuthorAndYear();//Найти названия книг данного автора, изданных с указанного года 
int BooksCountByProperty(std::string, std::string);
std::string GetPath();
void ShowOperationList();
void ChooseOperation();