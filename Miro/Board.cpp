#include "pch.h"
#include "Board.h"

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
