#pragma once
#include"TNode.h"

class BST
{
public:
	TNode* root;
	BST();
	BST(type);
	bool IsEmpty();
	void Insert(TNode**, type);
	bool Search(TNode*, type);
	void Delete(TNode**, type);
	void InOrder_Traverse(TNode*);
	TNode* FindMin(TNode*);
	TNode* GetParent(TNode*, type);
};
