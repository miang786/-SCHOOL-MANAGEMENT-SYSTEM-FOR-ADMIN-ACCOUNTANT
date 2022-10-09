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