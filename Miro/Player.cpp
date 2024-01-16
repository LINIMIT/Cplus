#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//CalculatePath();
	CalculatePath_Bfs();
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
		//이동
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
	/*
	//switch문 대신 사용
	//내가 바라보고 있는 방향 기준 앞에 있는 좌표는 무엇인가?
	Pos next = pos + front[_dir];
	//오른쪽 방향 90도 회전
	_dir = (_dir - 1) % DIR_COUNT;
	//왼쪽 방향 90도 회전
	_dir = (_dir + 1) % DIR_COUNT;*/
	
	while (pos != dest)
	{
		//현재 바라보는 방향 기준, 오른쪽으로 갈 수 있는지 확인
		int32  newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT ;
		;
		if (CanGo(pos + front[newDir]))
		{
			//오른쪽 방향 90도 회전
			_dir = newDir;
			//앞으로 한 보 전진
			pos += front[_dir];
			//좌표 기록
			_path.push_back(pos);

		}
		//벽이 막혀있다 앞으로 갈 수 있는지 확인
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			//왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;

		}
	}

	/*목적지 찾을 때까지
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

//Bfs를 이용한 길찾기
void Player::CalculatePath_Bfs()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos(); // 목적지

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	// extra)
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견됨.
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 목적지 도착
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}
	}

	_path.clear();
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
		temp[i] = _path[_path.size() - 1 - i];

	_path = temp;

}
