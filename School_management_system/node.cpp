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