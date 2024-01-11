#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//인접 리스트 방식
void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex>  v(6);

	//2차원 벡터
	vector<vector<int>> adjacent;
	adjacent.resize(6);

	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };


	//0-3 연결확인
	bool connected = false;

	int size = adjacent[0].size();
	for (int i = 0; i < size; i++)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
		{
			connected = true; // 간선연결 확인

		}
	}
}


//인접 행렬 방식
void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	//[X][0][X][0][X][X]
	//[0][X][0][0][X][X]
	//[X][X][X][X][X][X]
	//[X][X][X][X][0][X]
	//[X][X][X][X][X][X]
	//[X][X][X][X][0][X]

	//6개의 벡터를 만들고 그 벡터의 안에 X(false)를 넣어줌
	//adjacent[from][to]
	//메모리 소모 심하지만, 빠른 접근
	//인접 리스트는 일일이 검색해야하지만 행렬 방식에서는 그냥 인덱스를 검색하면됨
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	//0-3 연결확인
	bool connected = adjacent[0][3];

	vector<vector<int>> adjecent2 =
	{
		{-1,15,-1,35,-1,-1},
		{15,-1,+5,10,-1,-1},
		{-1,+5,-1,-1,-1,-1},
		{35,10,-1,-1,+5,-1},
		{-1,-1,-1,+5,-1,+5},
		{-1,-1,-1,-1,+5,-1}
	};
}
void main()
{


}