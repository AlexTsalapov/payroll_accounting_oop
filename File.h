#pragma once

#include <fstream>
#include "Queer.h"
#include "MyString.h"

template<class T>
class File
{
private:
	MyString address;
	ifstream file_input_stream;
	ofstream file_output_stream;
public:
	File();
	File(MyString str);
	~File();

	bool isInputOpen();
	bool isOutputOpen();

	void write(T obj);
	void read(T& obj);


	bool isEof();
};