#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
template <typename T> struct Block
{
	T info;
	Block* next, * prev;
};

template <typename T> class Queue
{
private:
	Block<T>* begin, * end;
public:
	Queue();
	Queue(const Queue& obj);
	~Queue();

	Queue& operator=(const Queue& obj);
	void deleteItemBeggin(int);
	void deleteItemEnd(int);
	int getSizeQueue();
	T getItem(int);
	void addItemBegin(T);
	void addItemEnd(T);
	void swapItem(int);
	void show();
	void showItem(int);
	void editItem(int);
	void swap2Item(int, int);
};


