#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
	T Data;
	Node *Left;
	Node *Right;
	Node *Parent;

	Node(const T& value)
	{
		Left = Right = Parent = NULL;
		this->Data = value;
	};
};

#endif