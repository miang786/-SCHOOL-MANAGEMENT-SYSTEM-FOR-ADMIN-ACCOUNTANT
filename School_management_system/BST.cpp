#include "BST.h"

BST::BST()
{
	this->root = NULL;
}
BST::BST(type val)
{
	this->root = new TNode(val);
}
bool BST::IsEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void BST::Insert(TNode** temp, type val)
{
	if (*temp == NULL)
	{
		TNode* node = new TNode(val);
		*temp = node;
	}
	else
	{
		if (val < (*temp)->data)
		{
			Insert(&(*temp)->left, val);
		}
		else if (val >= (*temp)->data)
		{
			Insert(&(*temp)->right, val);
		}
	}
}
bool BST::Search(TNode* temp, type val)
{
	if (temp == NULL)
	{
		return false;
	}
	else if (temp->data == val)
	{
		return true;
	}
	else if (val > temp->data)
	{
		return Search(temp->right, val);
	}
	else if (val < temp->data)
	{
		return Search(temp->left, val);
	}
	return false;
}
void BST::Delete(TNode** temp, type val)
{
	if (*temp == NULL)
	{
		cout << " Unfortunately!! The Node you are trying to delete is not found" << endl;
		return;
	}
	else if (val < (*temp)->data)
	{
		Delete(&(*temp)->left, val);
	}
	else if (val > (*temp)->data)
	{
		Delete(&(*temp)->right, val);
	}
	else if (val == (*temp)->data)
	{
		if (((*temp)->left == NULL) && ((*temp)->right == NULL))
		{
			TNode* Par = GetParent(*temp, val);
			if (Par->left == *temp)
			{
				Par->left = NULL;
			}
			else if (Par->right == *temp)
			{
				Par->right = NULL;
			}
			*temp = NULL;
			delete* temp;
		}
		else if ((((*temp)->left == NULL) && ((*temp)->right != NULL)) || (((*temp)->left != NULL) && ((*temp)->right == NULL)))
		{
			TNode* Par = GetParent(root, (*temp)->data);
			if ((*temp)->left != NULL)
			{
				if (Par->left == *temp)
				{
					Par->left = (*temp)->left;
					*temp = Par->left;
				}
				else if (Par->right == *temp)
				{
					Par->right = (*temp)->left;
					*temp = Par->right;
				}
			}
			else if ((*temp)->right != NULL)
			{
				if (Par->left == *temp)
				{
					Par->left = (*temp)->right;
					*temp = Par->right;
				}
				else if (Par->right == *temp)
				{
					Par->right = (*temp)->right;
					*temp = Par->right;
				}
			}
		}
		else if (((*temp)->left != NULL) && ((*temp)->right != NULL))
		{
			TNode* min = FindMin((*temp)->right);
			type m = min->data;
			Delete(&(*temp), min->data);
			(*temp)->data = m;
		}
	}
}
void BST::InOrder_Traverse(TNode* curr)
{
	if (curr != NULL)
	{
		InOrder_Traverse(curr->left);
		cout << " " << curr->data << " ";
		InOrder_Traverse(curr->right);
	}
}
TNode* BST::FindMin(TNode* temp)
{
	if (temp->left == NULL)
	{
		return temp;
	}
	else
	{
		return FindMin(temp->left);
	}
}
TNode* BST::GetParent(TNode* temp, type val)
{
	if (temp == NULL)
	{
		return NULL;
	}
	else if ((temp->left != NULL) && (temp->left->data == val))
	{
		return temp;
	}
	else if ((temp->right != NULL) && (temp->right->data == val))
	{
		return temp;
	}
	else if (val < temp->data)
	{
		return GetParent(temp->left, val);
	}
	else if (val > temp->data)
	{
		return GetParent(temp->right, val);
	}
	return temp;
}
