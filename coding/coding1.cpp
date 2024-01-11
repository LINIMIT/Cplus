#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//DFS(Depth)
//DFS == 재귀함수 == 스택
//BFS

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

//내가 방문한 목록
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	//인접 리스트
	/*adjacent = vector<vector<int>>(6);

	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	//인접 행렬

	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};
}

void DFS(int here)
{
	//방문한 인덱스 확인
	visited[here] = true;
	cout << "Visited : " << here << endl;

	//인접한 경로 체크(리스트 버전)

	//인접 리스트 0(V+E)
	//모든 정점마다 호출되기 때문에 v
	//간선의 개수 E 더하기
	/*const int size = adjacent[here].size();

	for (int i = 0; i < size; i++)
	{
		int there = adjacent[here][i];

		//이미 방문을 했는지 확인
		if (visited[there] == false)
		{
			DFS(there);
		}
	}*/


	//인접 행렬 0(V^2)
	//1.정점마다 한 번씩 이 함수에 들어오기 때문
	//2. 이 for문을 v만큼 실행하기 때문
	for (int there = 0; there < 6; there++)
	{
		//길은 있는가
		if (adjacent[here][there] == 0)
		{
			continue;
		}

		//아직 방문안한 곳에 한해서 방문
		if (visited[there] == false)
			DFS(there);
		
	}
}

void DFSAll()
{
	visited = vector<bool>(6, false);


	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			DFS(i);
	}
}
void main()
{
	CreateGraph();

	visited = vector<bool>(6, false);
	DFS(0);
}