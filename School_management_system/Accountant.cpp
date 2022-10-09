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