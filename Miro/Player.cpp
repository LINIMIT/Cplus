#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	CalculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		return;
	}
	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		//¿Ãµø
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	for (int i = 0; i < 20; i++)
	{
		pos += Pos(1, 0);
		_path.push_back(pos);
	}
}
