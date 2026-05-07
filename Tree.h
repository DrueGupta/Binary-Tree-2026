#pragma once
#include <iostream>
using namespace std;

template <typename TYPE>
struct Node
{
	TYPE value;
	Node<TYPE>* left;
	Node<TYPE>* right;
	Node(TYPE value)
	{
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
	Node() : Node((TYPE)NULL){}
};

template <typename TYPE>
class Tree
{
private:
	Node<TYPE>* root;
public:
	Tree()
	{
		this->root = nullptr;
	}
	Node<TYPE>* searchRec(TYPE target, Node<TYPE>* current)
	{
		if (current == nullptr)
			return(TYPE)NULL;
		else if (current->value = target)
		{
			return current;
		}
		else if (target < current->value)
		{
			return this->searchRec(target, current->left);
		}
		else if(target > current->value)
		{
			return this->searchRec(target, current->right);
		}
	}
	Node<TYPE>* search(TYPE value)
	{
		return this->searchRec(value, this->root);
	}
	void insertRec(TYPE value, Node<TYPE>* current)
	{
		if (current == nullptr)
		{
			this->root = new Node<TYPE>(value);
		}
		else if (value < current->value)
		{
			if (current->left == nullptr)
			{
				current->left = new Node<TYPE>(value);
			}
			else
			{
				this->insertRec(value, current->left);
			}
		}
		else
		{
			if (current->right == nullptr)
			{
				current->right = new Node<TYPE>(value);
			}
			else
			{
				this->insertRec(value, current->right);
			}
		}
	}
	void insert(TYPE value)
	{
		this->insertRec(value, this->root);
	}
	void printRec(Node<TYPE>* current)
	{
		if (current != nullptr)
		{
			cout << current->value << "  ";
			this->printRec(current->left);
			this->printRec(current->right);
		}
	}
	void print()
	{
		this->printRec(this->root);
		cout << endl;
	}
	Node<TYPE>* successor(Node<TYPE>* current)
	{
		current = current->right;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	Node<type>* removeRec(TYPE target, Node<TYPE>* current)
	{
		if (current == nullptr)
		{
			return current;
		}
		else if (target < current->value)
		{
			current->left = removeRec(target, current->left);
		}
		else if (target > current->value)
		{
			current->right = removeRec(target, current->right);
		}
		else
		{
			if (current->left == nulptr && current->right == nullptr)
			{
				return nullptr;
			}
			else if (current->left == nullptr)
			{
				Node<TYPE>* temp = current->right;
				delete current;
				return temp;
			}
			else if (current->right == nullptr)
			{
				Node<TYPE>* temp = current->left;
				delete current;
				return temp;
			}
			Node<TYPE>* temp = successor(current);
			current->value = temp->value;
			current->right = removeRec(temp->value, current->right);

		}
		return current;
	}
	void remove()
	{
		this->removeRec(value, this->root);
	}
};
