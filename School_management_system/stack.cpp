#include "stack.h"

stack::stack()
{
	mytop = NULL;
	s_top = -1;
}
bool stack::isempty()
{
	if (s_top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stack::push(type val)
{
	node* p = new node;
	p->data = val;
	p->next = NULL;
	if (stack::isempty())
	{
		head = p;
		mytop = head;
		s_top++;
	}
	else
	{
		node* q;
		q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
		mytop = p;
		s_top++;
	}
}
void stack::pop()
{
	if (s_top == -1)
	{
		cout << "\nList Is Already Empty.";
		system("pause");
		exit(0);
	}
	else
	{
		node* p, * q;
		p = head;
		q = NULL;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		cout << "\nThis Number Is Deleted : [ " << p->data << " ] \n";
		q->next = NULL;
		mytop = q;
		delete p;
		s_top--;
	}
}
void stack::display()
{
	node* p;
	p = head;
	cout << "{HEAD}==> ";
	while (p != NULL)
	{
		cout << " [ " << p->data << " ] --";
		p = p->next;
	}
	cout << "|";
	cout << "\n\nTop Of Stack Is : [ " << mytop->data << " ] \n\nTotal Nodes In List Are : " << s_top + 1 << endl << endl;
}
type stack::Top()
{
	if (stack::isempty())
	{
		return -1;
	}
	else
	{
		return mytop->data;
	}
}
