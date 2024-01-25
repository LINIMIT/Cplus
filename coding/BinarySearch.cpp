#include "BinarySearch.h"
#include <iostream>
#include <windows.h>

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearch::Print(Node* node, int x, int y)
{
}

Node* BinarySearch::Search(Node* node, int key)
{
	return nullptr;
}

Node* BinarySearch::Min(Node* node)
{
	return nullptr;
}

Node* BinarySearch::Max(Node* node)
{
	return nullptr;
}

Node* BinarySearch::Next(Node* node)
{
	return nullptr;
}

void BinarySearch::Insert(int key)
{
}

void BinarySearch::Delete(int key)
{
}

void BinarySearch::Delete(Node* node)
{
}
