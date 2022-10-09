#pragma once
#include "node.h"

class list		//-------------->> List Class
{
private:
	node* head;		
public:
	list();				//-------------->> Default Constructor
	bool emptylist();	//-------------->> Function For Checking The List Is Empty Or Not
	void insertend(string, string, string, char, float, float, bool);		//-------------->> Funtion For Inserting Student At The End of The List
	void traverse();		//-------------->> Function For Displaying The List
	int Std();		//-------------->> Function For Reading Number of Enrolled Students and Also Returning It
};