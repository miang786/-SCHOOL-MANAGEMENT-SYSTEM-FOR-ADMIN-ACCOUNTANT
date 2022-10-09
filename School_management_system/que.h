#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

class que
{
private:
	int* myArray;
	int size;
	int front, rear, count;
public:
	que(int);
	bool isEmpty();
	bool isFull();
	void enque(int);
	int getFront();
	int deque();
	void display();
};
