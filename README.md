Data Structure & Algorithms
CSC 221

PROJECT REPORT





MIAN AFZAAL ZAHOOR
01-134182-094



SUBMITTED TO: Sir Syed Saqlain Hassan
DATE OF SUBMITTION: 26th December, 2019




Department of Computer Sciences
BAHRIA UNIVERSITY, ISLAMABAD
School Management System For Administration And Accountant

Introduction:

	School management system is used to record details about the students and staff with a user-friendly interface and after taking the details it will also display the data of the record and later saving a copy of the same data into a file. 
Working:
	In main function the user is given some choices which are to login as an admin, login as an accountant, login as a manager etc. All these sections are password protected the user must have to enter his password to enter in his desired credential. The admin can change his password and the password of manager as well as accountant and can view all the data of the students and if the admin finds any mistake in the record after reviewing the record, he is given the choice to contact the responsible person who might solve the problem. (which is accountant or admin).
The accountant manages and keeps the record of fee of students and is able to change their fee status when the student will pay them fee. 
The manager will automate the enrolling system of students and will be able to delete any student data, and the Manager will deal with the details of student’s result and their performance during exams. Every entry is saved in files. 

Objectives:

	The main objective of this School management system is to make sure the data of the School is secure and whichever the details are entered are saved in the file.

It provides the facility to directly access the data by admin.

The data is secure until open by username and password.

Data is automatically added into the file of every information entered.

Secure data for any future consultation.

Construction:
                              Project is implemented using several concepts of Data Structures as much as possible which includes (list, nodes, classes, file handling).
	           This program will basically provide an ease to the user rather than managing the things separately. The manager will be able to control and modify things according to need when ever he/she wants to.	
CODE
HeaderFiles.h
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;


inline void endl(int a)		//-------------->> Inline Function For End line For Better View
{
	for (int i = 0; i <= a; i++)
	{
		cout << endl;
	}
}
inline void tab(int b)		//-------------->> Inline Function For Tab For Better View
{
	for (int i = 0; i <= b; i++)
	{
		cout << "\t" ;
	}
}
allfileHeader.h
#pragma once
#include"node.h"
#include"Accountant.h"
#include"Admin.h"
#include"HeaderFiles.h"
#include"list.h"
#include"manager.h"
#include"Student.h"
Admin.h
#pragma once
#include"HeaderFiles.h"
#include"manager.h"
#include"Accountant.h"

using namespace std;

class Admin    //------------------> Admin class
{
private:
	string Username;
	string Password;
public:
	Admin();			//-------------->> Default Constructor
	bool Login();		//-------------->> Function To Check Username And Password
	void Review();		//-------------->> Function To Rewiew Data From Files
	void Respond();		//-------------->> Function To Respond To Take Action After Reviewing Data
	bool AdminPass(string);		//-------------->> Function For Writing Password In File
	void ChangePAss();			//-------------->> Function For Changin Passwords
};
Admin.cpp
#include "Admin.h"
//*****************ADMIN'S INITILIZATION******************//
Admin :: Admin()
{
	string BTH;
	int i = 0;
	ifstream file("Admin.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, BTH);
			if (i == 0)
			{
				Username = BTH;
			}
			else if(i == 1)
			{
				Password = BTH;
			}
			i++;
		}
	}
	file.close();
}
//*****************ADMIN'S LOGIN******************//
bool Admin::Login()
{
	string User, Pass;    // variables to check username and password
	endl(2); tab(4);
	cout << "|------------------------------------------------------------------------------| " << endl; tab(4);
	cout << "|***********<<<<<<<<<<---------   LOGIN ACCOUNT:  --------->>>>>>>>>>**********| " << endl; tab(4);
	cout << "|------------------------------------------------------------------------------| "; endl(2); tab(7);
	///////////////////***********GETTING USER NAME*************/////////////////
	cout << " Enter username: ";
	cin.ignore();
	getline(cin, User);
	// for loop to convert lower case letters of username into upercase letters
	for (int i = 0; i < User.length(); i++)
	{
		User[i] = toupper(User[i]);
	}
	///////////////////***********GETTING USER PASSWORD*************/////////////////
	tab(7);
	cout << " Enter password: ";
	getline(cin, Pass);
	for (int i = 0; i < Pass.length(); i++)  // for loop to convert lower case letters of username into upercase letters
	{
		Pass[i] = toupper(Pass[i]);
	}

	//////condition to check username and password entered by user is correct or not//////////
	if (User == Username && Pass == Password)
	{
		endl(2); tab(7);
		cout << "LOGIN SUCESSFUL";
		endl(2); tab(7);
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		endl(2); tab(7);
		cout << "INVALID USERNAME OR PASSWORD" ;
		return false;
	}
}
//*****************ADMIN'S REVIEW******************//
void Admin::Review()
{
	bool con = true;		//-------------->> Bool For Condition
	while (con == true)
	{
		char choice;
		cout << "Press '1' To See Students Report." << endl << "==> ";
		cin >> choice;
		if (choice == '1')
		{
			ifstream file("StudentRec.txt");
			file.is_open();
			if (!file)
			{
				cout << "FILE NOT FOUND" << endl << endl;
			}
			else
			{
				string line;
				while (!file.eof())
				{
					getline(file, line);
					cout << line << endl;
				}
				file.close();
			}
			con = false;
		}
		else
		{
			cout << "Wrong Choice.Try Again." << endl << endl;
			system("pause");
			system("cls");
			con = true;
		}
	}
}
//*****************ADMIN'S RESPONCE******************//
void Admin::Respond()
{
	char choice;
	bool con = true;
	while (con == true)
	{
		cout << "For Any Query Contact The Responsible Employee.\n\n";
		cout << "Press '1' To Contact Manager." << endl;
		cout << "Press '2' To Contact Accountant." << endl;
		cout << "Press '3' To Contact Manager & Accoutant Both." << endl << "==> ";
		cin >> choice;
		if (choice == '1')
		{
			cout << "Your Query Has Been Notified To The Manager.The Manager Will Contact you Soon." << endl;
			con = false;
		}
		else if (choice == '2')
		{
			cout << "Your Query Has Been Notified To The Accoutant.The Accoutant Will Contact you Soon." << endl;
			con = false;
		}
		else if (choice == '3')
		{
			cout << "Your Query Has Been Notified To Both Manager & Accoutant.They Will Contact you Soon." << endl;
			con = false;
		}
		else
		{
			cout << "Wrong Choice.Try Again" << endl << endl;
			system("pause");
			system("cls");
			con = true;
		}
	}
}

bool Admin::AdminPass(string NP)
{
	bool op = false;
	ofstream file("Admin.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		op = true;
		file << Username << endl;
		file << NP << endl;
		Password = NP;
	}
	file.close();
	return op;
}
void Admin::ChangePAss()
{
	manager m;
	Accountant a;
	string NPass;
	char choice;
	cout << "Press '1' To Change Admin's Password.\nPress '2' To Change Manager's Password.\nPress '3' To Change Accountant's Password.\n==>  ";
	cin >> choice;
	cout << endl << endl;
	system("pause");
	system("cls");
	switch (choice)
	{
		case '1':
		{
			cout << "Enter New Pass For Admin : ";
			cin.ignore();
			getline(cin, NPass);
			if (AdminPass(NPass))
			{
				cout << "Admin's Password Changed SucessFully.";
			}
			else
			{
				cout << "PROCESS UNSUCESSFUL.TRY AGAIN";
			}
			break;
		}
		case '2':
		{
			cout << "Enter New Pass For Manager : ";
			cin.ignore();
			getline(cin, NPass);
			if (m.ManagerPass(NPass))
			{
				cout << "Manager's Password Changed SucessFully.";
			}
			else
			{
				cout << "PROCESS UNSUCESSFUL.TRY AGAIN";
			}
			break;
		}
		case '3':
		{
			cout << "Enter New Pass For Accountant : ";
			cin.ignore();
			getline(cin, NPass);
			if (a.AccountantPass(NPass))
			{
				cout << "Accountant's Password Changed SucessFully.";
			}
			else
			{
				cout << "PROCESS UNSUCESSFUL.TRY AGAIN";
			}
			break;
		}
		default:
		{
			cout << "Wrong Option Chossen" << endl << endl;
		}
	}
	cout << endl << endl;
	system("pause");
	system("cls");
}
Accountant.h
#pragma once
#include"HeaderFiles.h"
#include"list.h"

class Accountant		//-------------->> Accountant Class
{
private:
	string Username;
	string Password;
public:
	Accountant();			//-------------->> Default Constructor
	bool Login();			//-------------->> Function To Check Username And Password
	bool AccountantPass(string);	//-------------->> Function To Write Passwor In File
	void WriteDATAP(string, string, string, string);		//-------------->> Fuction For Writing List Of Students Who Have No Remaining Dues
	void WriteDATANP(string, string, string, string);		//-------------->> Fuction For Writing List Of Students Who Have Not PAid Their Dues
	void FeeStudents();		//-------------->> Fuction For Showing List Of Both Students Who Have Paid Their Fee As Well As not Paid 
	void rewrite(string);	//-------------->> Fuction For Editing File After Changing Status OF Fee OF A Student
	void PayFee();			//-------------->> Fuction For Paying Fee Of A Student
};
Accountant.cpp
#include "Accountant.h"

Accountant::Accountant()
{
	string BTH;
	int i = 0;
	ifstream file("Accountant.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, BTH);		//-------------->> Getting UserName From File
			if (i == 0)		//-------------->> First Line For UserName And Second For PAssword
			{
				Username = BTH;
			}
			else
			{
				Password = BTH;		//-------------->> Getting Password From File
			}
			i++;		//-------------->> Incrementing 'I' After first Line
		}
	}
	file.close();
}
bool Accountant::Login()		//-------------->> Function to check password of Accountant
{
	string User, Pass;    //------------->> variables to check username and password
	endl(2); tab(4);
	cout << "|------------------------------------------------------------------------------| " << endl; tab(4);
	cout << "|***********<<<<<<<<<<---------   LOGIN ACCOUNT:  --------->>>>>>>>>>**********| " << endl; tab(4);
	cout << "|------------------------------------------------------------------------------| " << endl << endl;

	///////////////////***********GETTING USER NAME*************/////////////////
	tab(7);
	cout << "Enter username: ";
	cin.ignore();
	getline(cin, User);	
	///////////***********for loop to convert lower case letters of username into upercase letters*********/////////
	for (int i = 0; i < User.length(); i++)
	{
		User[i] = toupper(User[i]);
	}
	///////////////////***********GETTING USER PASSWORD*************/////////////////
	tab(7);
	cout << "Enter password: ";
	getline(cin, Pass);
	for (int i = 0; i < Pass.length(); i++)  //-------------->> for loop to convert lower case letters of username into upercase letters
	{
		Pass[i] = toupper(Pass[i]);
	}

	//////*****condition to check username and password entered by user is correct or not********//////////
	if (User == Username && Pass == Password)
	{
		endl(1); tab(7);
		cout << "You Have Sucessfully Logged in press any key to continue....";
		endl(2); tab(7);
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		endl(2); tab(7);
		cout << "INVALID USERNAME OR PASSWORD";
	}
	return false;
}
bool Accountant::AccountantPass(string NP)		//-------------->> Function To Write and return password To file
{
	bool op = false;
	ofstream file("Accountant.txt");		//-------------->> Opening File For Writing 
	file.is_open();
	if (!file)		//-------------->> Checking That File Is Opened Or Not
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		op = true;
		file << Username << endl;
		file << NP << endl;
		Password = NP;
	}
	file.close();		//-------------->> Closing File
	return op;
}
void Accountant::WriteDATANP(string n, string c, string en, string s)		//-------------->> Funtion To Write Students Who Have Not Paid Their Fee
{
	ofstream file("StudentNPFee.txt", ios::app);		//-------------->> Opening File For Writing In File
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else    //-------------->> Writing Data In File
	{
		file << n << endl;
		file << c << endl;
		file << en << endl;
		file << s << endl << endl;
	}
	file.close();		//-------------->> Closing File
}
void Accountant::WriteDATAP(string n, string c, string en, string s)		//-------------->> Funtion To Write Students Who Have Paid Their Fee
{
	ofstream file("StudentPFee.txt", ios::app);		//-------------->> Opening File For Writing In File
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		file << n << endl;
		file << c << endl;
		file << en << endl;
		file << s << endl << endl;
	}
	file.close();		//-------------->> Closing File
}
void Accountant::FeeStudents()
{
	string h;		//-------------->> String For Reading From File
	int NPcount = 0;			//-------------->> Counting Students Who Have Not Paid Their Fee
	string na, cl, en, s;		//-------------->> Variables For Name , Class , Enrolment no. , Section
	int i = 1;
	remove("StudentPFee.txt");		//-------------->> Clearing Old List Of Unpaid Students 
	remove("StudentNPFee.txt");		//-------------->> Closing Old List Of Unpaid Students 
	ifstream file1("StudentRec.txt");		//-------------->> Opening File For Reading
	file1.is_open();
	if (!file1)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		while (!file1.eof())
		{
			getline(file1, h);
			cout << h << endl;
		}
	}
	file1.close();
	ifstream file("StudentRec.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, h);
			if (i == 2)			//-------------->> For geting only Name of student From file
			{
				na = h;
			}
			else if (i == 3)	//-------------->> For geting only Enrollment number of student From file
			{
				en = h;
			}
			else if (i == 4)	//-------------->> For geting only Class of student From file
			{
				cl = h;
			}
			else if (i == 5)	//-------------->> For geting only Section of student From file
			{
				s = h;
			}
			if (i == 8)			//-------------->> It Checks The Status of Fee From File
			{
				if (h[6] == 'P')		//-------------->> Checking From File
				{
					WriteDATAP(na, cl, en, s);		//-------------->> Writing in File
				}
				else if(h[6] == 'N')
				{
					WriteDATANP(na, cl, en, s);		//-------------->> Writing In File
					NPcount++;		//-------------->> Increasing Number of Students Who have Not Paid their Fee
				}
			}
			if (i == 9)		//-------------->> For going to next Student In File
			{
				i = 0;
			}
			i++;
		}
	}
	file.close();
	if (NPcount == 0)
	{
		cout << "ALL STUDENTS HAVE PAID THEIR FEE's" << endl;
	}
	else
	{
		cout << NPcount << " NUMBER OF STUDENTS HAVE NOT PAID THEIR FEE" << endl << endl;
		ifstream file1("StudentNPFee.txt");
		file1.is_open();
		if (!file1)
		{
			cout << "FILE NOT OPEN." << endl;
		}
		else
		{
			while (!file1.eof())
			{
				getline(file1, h);
				cout << h << endl;
			}
		}
		file1.close();
		cout << "\n\nABOVE STUDENT PARENT's HAVE BEEN NOTIFIED FOR CLEARING THEIR DUES ASAP." << endl << endl;
	}
}
void Accountant::rewrite(string h)		//-------------->> Funtion For Writing Data in File
{
	ofstream file("Extra.txt", ios::app);		//-------------->>Opening File For Writing
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		file << h << endl;
	}
	file.close();		//-------------->> Closing File
}
void Accountant::PayFee()		//-------------->> Function For Paying Fee Of Students
{
	cout << "STUDENTS WITH THEIR FEES." << endl << endl;
	string fl;		//-------------->> String For Reading From File
	ifstream  file1("StudentRec.txt");		//-------------->> Opening File For Showing Full List of Students
	file1.is_open();
	if (!file1)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		while (!file1.eof())
		{
			getline(file1, fl);
			cout << fl << endl;		//-------------->> Showing Full List of Students
		}
	}
	file1.close();
	string num, match = "STUDENT NUMBER : ";
	bool valid = false;
	int size, i, j, count = 8;
	cout << "Enter Student Number To Pay Fee : ";
	cin >> num;
	match = match + num;
	ifstream file("StudentRec.txt");		//-------------->> Reading Data From File To Change Status Of Fee
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{ 
		while (!file.eof())
		{
			getline(file, fl);
			if (fl == match)
			{
				rewrite(fl);
				for (int i = 0; i < 7; i++)
				{
					getline(file, fl);
					if (i != 6)
					{
						rewrite(fl);
					}
					else if (i == 6)
					{
						rewrite("FEE : PAID");
						valid = true;
					}
				}
			}
			else
			{
				rewrite(fl);
			}
		}
	}
	
	file.close();
	if (valid)
	{
		cout << "FEE PAID SUCESSFULLY FOR STUDENT " << num << endl;
	}
	else
	{
		cout << "RECORD NOT FOUND." << endl;
	}
	remove("StudentRec.txt");		//-------------->> Removing Old File 
	rename("Extra.txt", "StudentRec.txt");		//-------------->> Renaming The Edited File
}
node.h
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
node.cpp
#include "node.h"
node::node()
{
	ifstream file("count.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		file >> TotalStud;
	}
	file.close();
	Nnext = NULL;
}
bool node::isEmpty()
{
	if (TotalStud == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
node::node(string N, string C, string E, char S, float P, float A, bool B)
{
	ifstream file1("count.txt");
	file1.is_open();
	if (!file1)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		file1 >> TotalStud;
	}
	file1.close();
	data.SetStudent(N, E, C, S, P, A, B);
	TotalStud++;
	ofstream file("count.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		file << TotalStud;
	}
	file.close();
	Nnext = NULL;
}
int node::TtlSt()
{
	return TotalStud;
}
void node::Print()
{
	data.DisplayStudent();
}
Student.h
#pragma once
#include"HeaderFiles.h"

class Student		//-------------->> Student Class
{
public:
	string Name;		//-------------->> Variable For Name Of Student
	string ClassE;		//-------------->> Variable For Class Of Student
	string Enroll;		//-------------->> Variable For Enrollment Of Student
	float Percentage;	//-------------->> Variable For Percentage Of Student Of His Results
	float Attendence;	//-------------->> Variable For Student's Attendence In Class
	char Section;		//-------------->> Variable For Section Of Student
	bool feeStat;		//-------------->> Variable For Showing The Status Of Fee Of The Student
	Student();			//-------------->> Default Constructor
	void SetStudent(string, string, string, char, float, float, bool);		//-------------->> Default Parameterized Constructor
	void DisplayStudent();		//-------------->> Function For Dislaying Data Of Student
};
Student.cpp
#include "Student.h"
//COMPLETE CLASS
Student::Student()
{
	Name = "\0";
	Enroll = "\0";
	ClassE = "\0";
	Section = '\0';
	Percentage = 0;
	Attendence = 0;
	feeStat = false;
}
void Student::SetStudent(string N, string E, string C, char S, float P, float A, bool B)
{
	Name = N;
	ClassE = C;
	Enroll = E;
	Section = S;
	Percentage = P;
	Attendence = A;
	feeStat = B;
}
void Student::DisplayStudent()
{
	cout << "\nStudent Name : " << Name << endl;
	cout << "Class : " << ClassE << endl;
	cout << "Section : " << Section << endl;
	cout << "Enrollment : " << Enroll << endl;
	cout << "Percentage : " << Percentage << endl;
	cout << "Attendance : " << Attendence << endl;
	if (feeStat == true)
	{
		cout << "FEE STATUS : PAID" << endl;
	}
	else
	{
		cout << "FEE STATUS : NOT PAID" << endl;
	}
}
list.h
#pragma once
#include "node.h"

class list		//-------------->> List Class
{
private:
	node* head;		
public:
	list();				//-------------->> Default Constructor
	bool emptylist();	//-------------->> Function For Checking The List Is Empty Or Not
	void insertend(string, string, string, char, float, float, bool);		//-------------->> Funtion For Inserting Student At The End of The List
	void traverse();		//-------------->> Function For Displaying The List
	int Std();		//-------------->> Function For Reading Number of Enrolled Students and Also Returning It
};
list.cpp
#include "list.h"

list::list()
{
	head = NULL;
}
bool list::emptylist()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void list::insertend(string N, string E, string C, char S, float P, float A, bool B)
{
	node* p = new node(N, C, E, S, P, A, B);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		node* q;
		q = head;
		while (q->Nnext != NULL)
		{
			q = q->Nnext;
		}
		q->Nnext = p;
	}
}
int list::Std()
{
	int number;
	ifstream file("count.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		file >> number;
	}
	file.close();
	return number;
}
void list::traverse()
{
	node* p = head;
	cout << "TOTAL NUMBER OF STUDENT ARE LISTED BELOW\n\n";
	int i = 1;
	while (p != NULL)
	{
		cout << "STUDENT NUMBER : " << i << endl;
		p->Print();
		p = p->Nnext;
	}
}
manager.h
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
manager.cpp
#include "manager.h"

manager::manager()
{
	string BTH;
	int i = 0;
	ifstream file("Manager.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, BTH);
			if (i == 0)
			{
				Username = BTH;
			}
			else
			{
				Password = BTH;
			}
			i++;
		}
	}
	file.close();
}
bool manager::Login()
{
	string User, Pass;    // variables to check username and password
	endl(2); tab(4);
	cout << "|------------------------------------------------------------------------------| " << endl; tab(4);
	cout << "|***********<<<<<<<<<<---------   LOGIN ACCOUNT:  --------->>>>>>>>>>**********| " << endl; tab(4);
	cout << "|------------------------------------------------------------------------------| "; endl(2); tab(7);

	///////////////////***********GETTING USER NAME*************/////////////////
	cout << " Enter username: ";
	cin.ignore();
	getline(cin, User);
	tab(7);
	// for loop to convert lower case letters of username into upercase letters
	for (int i = 0; i < User.length(); i++)
	{
		User[i] = toupper(User[i]);
	}
	///////////////////***********GETTING USER PASSWORD*************/////////////////
	cout << " Enter password: ";
	getline(cin, Pass);
	endl(2); tab(7);
	for (int i = 0; i < Pass.length(); i++)  // for loop to convert lower case letters of username into upercase letters
	{
		Pass[i] = toupper(Pass[i]);
	}

	//////condition to check username and password entered by user is correct or not//////////
	if (User == Username && Pass == Password)
	{
		cout << "LOGIN SUCESSFUL\n" << endl;
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		cout << "INVALID USERNAME OR PASSWORD\n" << endl;
		return false;
	}
}
void manager::AddStudent()
{
	string na, en, cl;
	char s, choic;
	float pe, at;
	bool stat;
	cout << "\nEnter Student Name : ";
	cin.ignore();
	getline(cin, na);
	cout << "Enter Enrollment Number : ";
	cin >> en;
	cout << "Enter Class : ";
	cin >> cl;
	cout << "Enter Section : ";
	cin >> s;
	cout << "Enter Result Percentage : ";
	cin >> pe;
	cout << "Enter Attendence Percentage : ";
	cin >> at;
	cout << "Fee Status => Press 'P' For Paid OR Press 'N' For Not Paid : ";
	cin >> choic;
	choic = toupper(choic);
	if (choic == 'P')
	{
		stat = true;
	}
	else
	{
		stat = false;
	}
	Stds.insertend(na, en, cl, s, pe, at, stat);
	cout << endl << endl;
	int ttl = Stds.Std();
	system("pause");
	system("cls");
	cout << "RECORD SAVED FOR FOLLOWING STUDENT." << endl << endl;
	cout << "STUDENT NUMBER : " << ttl << "\nSTUDENT NAME : " << na << "\nENROLLMENT : " << en << "\nCLASS : " << cl << "\nSECTION : " << s << "\nRESULT % : " << pe << "\nATTENDENCE : " << at << endl;
	if (choic == 'P')
	{
		cout << "FEE PAID" << endl;
	}
	else
	{
		cout << "FEE NOT PAID" << endl;
	}
	ofstream file("StudentRec.txt", ios::app);
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl << endl;
	}
	else
	{
		file << "STUDENT NUMBER : " << ttl << endl;
		file << "NAME : " << na << endl;
		file << "ENROLLMENT : " << en << endl;
		file << "CLASS : " << cl << endl;
		file << "SECTION : " << s << endl;
		file << "RESULT PERCENTAGE : " << pe << endl;
		file << "ATTENDENCE PERCENTAGE : " << at << endl;
		if (choic == 'P')
		{
			file << "FEE : PAID" << endl << endl;
		}
		else
		{
			file << "FEE : NOTP" << endl << endl;
		}
	}
	file.close();
}
bool manager::ManagerPass(string NP)
{
	bool op = false;
	ofstream file("Manager.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN." << endl;
	}
	else
	{
		op = true;
		file << Username << endl;
		file << NP << endl;
		Password = NP;
	}
	file.close();
	return op;
}
void manager::DisplayCurrent()
{
	cout << "NUMBER OF STUDENTS ENROLLED TODAY ARE\n\n";
	Stds.traverse();
}
void manager::AgainDATA(string S)
{
	ofstream file1("Extra.txt", ios::app);
	file1.is_open();
	if (!file1)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		file1 << S << endl;
	}
	file1.close();
}
void manager::DeleteStudent()
{
	string num;
	string fl, match = "STUDENT NUMBER : ";
	bool valid = false;
	int size, i, j, count = 8, cnt;
	cout << "Enter Student Number To Delete : ";
	cin >> num;
	match = match + num;
	ifstream file("StudentRec.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, fl);
			if (fl == match)
			{
				for (int i = 0; i < 8; i++)
				{
					getline(file, fl);
				}
				valid = true;
			}
			else
			{
				AgainDATA(fl);
			}
		}
	}
	file.close();
	if (valid)
	{
		cout << "RECORD OF STUDENT WITH FOLLOWING NUMBER IS " << num << " DELETED." << endl;
	}
	else
	{
		cout << "RECORD NOT FOUND." << endl;
	}
	remove("StudentRec.txt");
	rename("Extra.txt", "StudentRec.txt");
}
void manager::DisplayAll()
{
	string h;
	ifstream file("StudentRec.txt");
	file.is_open();
	if (!file)
	{
		cout << "FILE NOT OPEN" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, h);
			cout << h << endl;
		}
	}
	file.close();
}
Source.cpp
#include"allfileHeader.h"

void Menu()
{
	char choice1, choice2, choice3;
	Admin Ad;
	manager Mg;
	Accountant Ac;
	bool condi = false;
	while (true)
	{
		system("color a1");
		cout << "Press 'A' To Login As An Admin.\nPress 'M' To Login As A Manager.\nPress 'C' To Login As An Accountant.\nPress 'E' To Exit.\n==> ";
		cin >> choice1;
		system("cls");
		choice1 = toupper(choice1);
		switch (choice1)
		{
		case 'A':
		{
			system("color b5");
			condi = Ad.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN ADMIN\n\n\n";
				while (true)
				{
					cout << "Press '1' To Review Stats.\nPress '2' To Change Passwords.\nPress '3' To Exit To Main Menu.\n==> ";
					cin >> choice3;
					if(choice3 == '1')
					{
						Ad.Review();
						cout << endl << endl;
						cout << "\t\tPress 'Q' If You Have Any Query In Above Details.Else Press Any Other Key To Exit To Main Menu.\n==> ";
						cin >> choice2;
						choice2 = toupper(choice2);
						if (choice2 == 'Q')
						{
							system("cls");
							Ad.Respond();
						}
					}
					else if (choice3 == '2')
					{
						Ad.ChangePAss();
					}
					else if (choice3 == '3')
					{
						break;
					}
					else
					{
						cout << "WRONG CHOICE." << endl;
					}
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'M':
		{
			system("color 20");
			condi = Mg.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN MANAGER\n\n\n";
				while (true)
				{
					cout << "Press '1' To Add New Student.\nPress '2' To Display Students Enrolled Today.\nPress '3' To Display All Students Record.\nPress '4' To Delete Any Student Data.\nPress '5' To Exit To Main Menu.\n==> ";
					cin >> choice2;
					cout << endl << endl;
					system("pause");
					system("cls");
					if (choice2 == '1')
					{
						Mg.AddStudent();
					}
					else if (choice2 == '2')
					{
						Mg.DisplayCurrent();
					}
					else if (choice2 == '3')
					{
						Mg.DisplayAll();
					}
					else if (choice2 == '4')
					{
						Mg.DisplayAll();
						cout << "\n\nSELECT STUDENT FROM ABOVE LIST.\n\n";
						Mg.DeleteStudent();
					}
					else if (choice2 == '5')
					{
						break;
					}
					else
					{
						cout << "WRONG OPTION.";
					}
					cout << endl << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'C':
		{
			system("color 20");
			char choice;
			condi = Ac.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN Accountant\n\n\n";
				while (true)
				{
					system("cls");
					cout << "Press '1' To See The List Of Students And Their Fee Status" << endl;
					cout << "Press '2' To Pay Fee of the student." << endl;
					cout << "Press '3' To exit To Main Menu.\n-->> ";
					cin >> choice;
					if (choice == '1')
					{
						Ac.FeeStudents();
					}
					else if (choice == '2')
					{
						Ac.PayFee();
					}
					else if (choice == '3')
					{
						break;
					}
					else
					{
						cout << "Wrong Choice Entered." << endl;
					}
					system("pause");
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'E':
		{
			system("cls");
			system("color a4");
			cout << "Thanks For Using The Program." << endl << endl;
			system("pause");
			exit(0);
		}
		default:
		{
			cout << "Wrong Choice.Try Again.";
		}
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}
}


int main()
{
	Menu();
	_getch();
	return 0;
}

OUTPUT
ADMIN
        
MANAGER

Accountant 

  
EXIT


