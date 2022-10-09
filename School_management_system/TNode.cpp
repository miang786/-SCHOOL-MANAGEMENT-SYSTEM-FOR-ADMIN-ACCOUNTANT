#include"TNode.h"

TNode::TNode()
{
	data = 0;
	left = right = NULL;
}
TNode::TNode(type val)
{
	data = val;
	left = right = NULL;
}
