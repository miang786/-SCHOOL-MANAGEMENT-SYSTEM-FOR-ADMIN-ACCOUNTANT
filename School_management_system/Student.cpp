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