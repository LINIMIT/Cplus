#include "BinarySearch.h"
#include <iostream>
#include <windows.h>

using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearch::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

Node* BinarySearch::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;
	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
	return nullptr;
}

Node* BinarySearch::Min(Node* node)
{

	if (node == nullptr)
		return nullptr;

	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearch::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;
	return nullptr;
}

Node* BinarySearch::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearch::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

}

void BinarySearch::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearch::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		return;


}

void BinarySearch::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;

}
