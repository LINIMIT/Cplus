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
		//�̵�
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Pos dest = _board->GetExitPos();

	/*for (int i = 0; i < 20; i++)
	{
		pos += Pos(1, 0);
		_path.push_back(pos);
	}*/


	Pos front[4] =
	{
		Pos(-1,0),
		Pos(0,-1),
		Pos(1,0),
		Pos(0,1)
	};

	//switch�� ��� ���
	//���� �ٶ󺸰� �ִ� ���� ���� �տ� �ִ� ��ǥ�� �����ΰ�?
	Pos next = pos + front[_dir];
	//������ ���� 90�� ȸ��
	_dir = (_dir - 1) % DIR_COUNT;
	//���� ���� 90�� ȸ��
	_dir = (_dir + 1) % DIR_COUNT;

	while (pos != dest)
	{
		//���� �ٶ󺸴� ���� ����, ���������� �� �� �ִ��� Ȯ��

	}

	/*������ ã�� ������
	while (pos != dest)
	{
		switch (_dir)
		{
		case dir_up:
			pos next = pos + pos(-1, 0);
			break;
		case dir_left:
			pos next = pos + pos(0, -1);
			break;
		case dir_down:
			pos next = pos + pos(1, 0);
			break;
		case dir_right:
			pos next = pos + pos(0, 1);
			break;

		}
	}*/

}
