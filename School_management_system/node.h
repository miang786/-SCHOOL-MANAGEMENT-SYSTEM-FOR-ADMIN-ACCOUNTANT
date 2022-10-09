#pragma once
#include"HeaderFiles.h"
#include"Student.h"

class node
{
public:
	int TotalStud;		//-------------->> Varible Which Stores Total Number Of Enrolled Students From File
	Student data;		//-------------->> Variable OF Student Class
	node* Nnext;		//-------------->> Pointer Of Node For Making List

	node();				//-------------->> Default Constructor
	node(string, string, string, char, float, float, bool);		//-------------->> Default Paramiterized Constructor 
	bool isEmpty();		//-------------->> Function To Check The Node is Empty Or Not
	int TtlSt();		//-------------->> Funtion For Returning Total Number of Enrolled Students From List
	void Print();		//-------------->> Funtion For Displaying Node (i.e Student Data)
};