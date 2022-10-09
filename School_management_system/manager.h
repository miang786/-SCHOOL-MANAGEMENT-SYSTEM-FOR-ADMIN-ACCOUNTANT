#pragma once
#include"HeaderFiles.h"
#include"list.h"

class manager	//-------------->> Accountant Class
{
private: 
	string Username;
	string Password;
	list Stds;		//-------------->> List Of Students
public:
	manager();			//-------------->> Default Constructor
	bool Login();		//-------------->> Function To Check Username And Password
	void AddStudent();	//-------------->> Function To Add Students In The List
	bool ManagerPass(string);	//-------------->> Function For Writing Password in The File
	void DisplayCurrent();		//-------------->> Function For Displaying Today's Enrolled students By Traversing The List
	void DisplayAll();			//-------------->> Function For Displaying All Enrolled Students From File
	void AgainDATA(string);		//-------------->> Writing Data In File For Replacing 
	void DeleteStudent();		//-------------->> Function For Deleting A Student From The List
};