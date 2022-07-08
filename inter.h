#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "MyString.h"
#include "Queer.cpp"
#include"Assembly_department.h"
#include"Loader.h"
#include"Paint_department.h"
#include"Marketolog.h"
#include"Economist.h"
#include"User.h"
#include"Admin.h"


template<class T>
class Interface
{
	T ob;
public:
	Interface() {}
	~Interface() {}
	void menu();
	void fun();
	void funAdmin();
	void menuAdmin();
	void menuAdd(MyString,MyString);
	void editAdmin();
	void sort(Queue<T>& st);
	void readOutFile(Queue<T>& st);
	void writeInFile(Queue<T>& st);
};


