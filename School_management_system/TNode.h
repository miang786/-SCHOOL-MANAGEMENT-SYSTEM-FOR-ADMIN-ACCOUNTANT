#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

typedef int type;

class TNode
{
public:
	type data;
	TNode* left;
	TNode* right;
	TNode();
	TNode(type);
};
