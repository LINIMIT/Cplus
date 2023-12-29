#include "pch.h"
#include "Board.h"

const char* TILE = "¤±";
Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size)
{
	_size = size;
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int32 y = 0; 25; y++)
	{
		for (int32 x = 0; x < 25; x++) 
		{
			ConsoleColor color = GetTileColor(Pos(x, y));
			ConsoleHelper::SetCursorColor(color);
			cout << TILE;
		}
		cout << endl;
	}
}

void Board::GenerateMap()
{
}

TileType Board::GetTileType(Pos pos)
{
	return TileType();
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	return ConsoleColor();
}
