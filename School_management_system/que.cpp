#include "que.h"

que::que(int a)
{
	myArray = new int[a];
	front = 0;
	rear = 0;
	count = 0;
	size = a;
}
bool que::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
		return false;
}
bool que::isFull()
{
	if (count == size - 1)
	{
		return true;
	}
	else
		return false;
}
void que::enque(int a)
{
	if (isFull())
	{
		cout << " Que is already full " << endl;
	}
	else
	{
		myArray[rear] = a;
		rear = (rear + 1) % size;
		count++;
		cout << " value entered" << endl;
		system("pause");
		system("cls");
	}
}
int que::getFront()
{
	if (isEmpty())
	{
		cout << " Que is aready empty " << endl;
		return -1;
	}
	else
	{
		return myArray[front];
	}
}
int que::deque()
{
	if (isEmpty())
	{
		cout << " Que is already empty " << endl;
		return -1;
	}
	else
	{
		int temp;
		temp = myArray[front];
		front = (front + 1) % size;
		count--;
		cout << " value dequed" << endl;
		system("pause");
		system("cls");
		return temp;
	}
}
void que::display()
{
	if (isEmpty())
	{
		cout << " Que is already empty " << endl;
	}
	else
	{
		while (front != rear)
		{
			cout << myArray[front];
			front = (front + 1) % size;
		}
	}
}
