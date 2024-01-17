#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//CalculatePath();
	//CalculatePath_Bfs();
	CalculatePath_AStar();
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
		int32  newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
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


struct PQNode
{
	PQNode(int32 f, int32 g, Pos pos) : f(f), g(g), pos(pos) { }

	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32 f;
	int32 g;
	Pos pos;


};

void Player::CalculatePath_AStar()
{
	//  F = G + H
	//  F = 최종 점수
	//  G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	//  H = 목적지에서 해당 좌표까지 이동하는데 드는 비용

	Pos start = _pos;
	Pos pos = _pos;
	Pos dest = _board->GetExitPos(); // 목적지

		Pos front[] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
		Pos(-1, -1), // UP_LEFT
		Pos(1, -1), // DOWN_LEFT
		Pos(1, 1), // DOWN_RIGHT
		Pos(-1, 1), // UP_RIGHT
	};

	int32 cost[] =
	{
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14
	};

	const int32 size = _board->GetSize();

	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	//(y,x)에 방문했는지 여부(방문목록)
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	//부모추적용도
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));


	//예약 시스템 구현
	//뒤늦게 더 좋은 경로가 나올 수 있기를 대비함


	//오픈리스트(발견목록)
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	//초기값
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));

		pq.push(PQNode(g + h, g, start));
		
		best[start.y][start.x] = g+h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보

		PQNode node = pq.top();
		pq.pop();

		//이미 방문한 경우
		if (closed[node.pos.y][node.pos.x])
			continue;
		//더 우수한 후보가 있는 경우
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		//방문
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < 8; dir++)
		{
		
			Pos nextPos = node.pos + front[dir];
			
			if (CanGo(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));


			//다른 경로에서 더 빠른 길을 찾으면 스팁
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode(g + h, g, nextPos));
			parent[nextPos.y][nextPos.x] = node.pos;
		}
	}

	_path.clear();
	Pos pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	/*vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
		temp[i] = _path[_path.size() - 1 - i];

	_path = temp;*/

	std::reverse(_path.begin(), _path.end());
}
