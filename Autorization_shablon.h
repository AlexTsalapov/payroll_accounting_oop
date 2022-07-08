#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include"MyString.h"
using namespace std;

template <typename T> class Autorization_shablon
{

	T obj;
public:
	void menuAutorization();
	bool setQueue( MyString login, MyString password);
	bool isLoginNew(MyString login);
	

};

