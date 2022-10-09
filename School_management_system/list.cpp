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