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