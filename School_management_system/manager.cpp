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