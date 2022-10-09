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