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