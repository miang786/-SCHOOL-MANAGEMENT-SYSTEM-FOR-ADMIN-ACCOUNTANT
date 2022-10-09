#pragma once
#include"node.h"

class stack
{
private:
	node* head;
	node* mytop;
	int s_top;
public:
	stack();
	bool isempty();
	void push(type);
	void pop();
	void display();
	type Top();
};
