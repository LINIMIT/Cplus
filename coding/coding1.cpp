#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//DFS(Depth)
//DFS == ����Լ� == ����
//BFS

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

//���� �湮�� ���
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	//���� ����Ʈ
	/*adjacent = vector<vector<int>>(6);

	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	//���� ���

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
	//�湮�� �ε��� Ȯ��
	visited[here] = true;
	cout << "Visited : " << here << endl;

	//������ ��� üũ(����Ʈ ����)

	//���� ����Ʈ 0(V+E)
	//��� �������� ȣ��Ǳ� ������ v
	//������ ���� E ���ϱ�
	/*const int size = adjacent[here].size();

	for (int i = 0; i < size; i++)
	{
		int there = adjacent[here][i];

		//�̹� �湮�� �ߴ��� Ȯ��
		if (visited[there] == false)
		{
			DFS(there);
		}
	}*/


	//���� ��� 0(V^2)
	//1.�������� �� ���� �� �Լ��� ������ ����
	//2. �� for���� v��ŭ �����ϱ� ����
	for (int there = 0; there < 6; there++)
	{
		//���� �ִ°�
		if (adjacent[here][there] == 0)
		{
			continue;
		}

		//���� �湮���� ���� ���ؼ� �湮
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