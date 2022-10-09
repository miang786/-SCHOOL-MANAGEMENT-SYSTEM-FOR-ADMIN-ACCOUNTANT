#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;


inline void endl(int a)		//-------------->> Inline Function For End line For Better View
{
	for (int i = 0; i <= a; i++)
	{
		cout << endl;
	}
}
inline void tab(int b)		//-------------->> Inline Function For Tab For Better View
{
	for (int i = 0; i <= b; i++)
	{
		cout << "\t" ;
	}
}