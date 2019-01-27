#ifndef TREE_H
#define TREE_H


template <typename T>
class Tree
{
private:
	Node<T> *Root;

	void InsertTree(Node<T> *node,const T& value)
	{
		if (node->Data > value)
		{
			if (!(node->Left))
			{
				node->Left = new Node<T>(value);
				node->Left->Parent = node;
			}

			else
				InsertTree(node->Left, value);
		}
		else if (node->Data < value)
		{
			if (!(node->Right))
			{
				node->Right = new Node<T>(value);
				node->Right->Parent = node;
			}
			else
				InsertTree(node->Right, value);
		}
		else
			std::cout << "Value exists in tree";
	};

	int searchTree(Node<T> const *node,const T& value) const
	{
		if (node->Data == value)
			return 1;
		else if (value < node->Data && node->Left)
			return searchTree(node->Left, value);
		else if (value > node->Data && node->Right)
			return searchTree(node->Right, value);
		else
			return 0;
	};

	int TreeSize(Node<T> *node) const
	{
		if (node)
		{
			return TreeSize(node->Left) + TreeSize(node->Right) + 1;
		}
		return 0;
	};
	
	std::ostream& PrintTree(Node<T> const *node, std::ostream& Out) const
	{
		if (!node) return Out;
		PrintTree(node->Left, Out);
		Out << node->Data << ", ";
		PrintTree(node->Right, Out);
		return Out;
	};

	void DeleteTree(Node<T> *root)
	{
		if (root)
		{
			DeleteTree(root->Left);
			DeleteTree(root->Right);
			delete root;
		}
	};

public:
	Tree() { };
	~Tree()
	{
		DeleteTree(Root);
	};

	void add(const T& val)
	{
		if (Root)
			InsertTree(Root, val);
		else
			Root = new Node<T>(val);
	}
	void search(const T& val) const
	{
		if (Root)
		{
			if (searchTree(Root, val))
				std::cout << "Found " << val << std::endl;
			else
				std::cout << "Not Found " << val << std::endl;
		}
		else
		{
			std::cout << "Initialize tree first in order to search in" << std::endl;
		}
	}
	void size() const
	{
		if (Root)
		{
			std::cout << "Tree size is: " << TreeSize(Root) << std::endl;
		}
		else
		{
			std::cout << "Empty tree cannot be sized" << std::endl;
		}
	}

	friend std::ostream& operator << (std::ostream& out, const Tree<T>& t)
	{
		out << "Printing Tree:" << std::endl;
		return t.PrintTree(t.Root, out);
	}
};

#endif