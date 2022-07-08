
#pragma once 
#include "File.h"

template<class T> File<T>::File()
{
	address = "";
}

template<class T> File<T>::File(MyString str)
{
	address = str;
}

template<class T> File<T>::~File()
{
	file_input_stream.close();
	file_output_stream.close();
}


template<class T> bool File<T>::isInputOpen()
{
	file_input_stream.open(address.getStr(), std::ios::in);

	if (!file_input_stream.is_open())
	{
		system("color 4");
		cout << "  Ошибка, не удалось открыть файл" << endl << " ";
		system("pause");
		system("cls");
		system("color 2");
		ofstream in(address.getStr(), std::ios::in);
		in.close();

		return false;
	}

	return true;
}

template<class T> bool File<T>::isOutputOpen()
{
	file_output_stream.open(address.getStr(), ios::out);

	if (!file_output_stream.is_open())
	{
 		system("color 4");
		std::cout << "  Ошибка, не удалось открыть файл"  << std::endl << std::endl << " ";
		system("pause");
		system("cls");
		system("color 2");

		ofstream out(address.getStr(), ios::out);
		out.close();

		return true;
	}

	return true;
}


template<class T> void File<T>::write(T obj)
{
	file_output_stream << obj;
}

template<class T> void File<T>::read(T& obj)
{
	file_input_stream >> obj;
}


template<class T> bool File<T>::isEof()
{
	if (file_input_stream.eof())
	{
		return true;
	}

	return false;
}