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

//���� �湮�� ���(DFS)
vector<bool> visited;

//�߰��� ���
vector<bool> discovered;


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


void BFS(int here)
{

	//������ ���� �߰ߵǾ�����?
	vector<int> parent(6, -1);
	//���������� ��ŭ ������ �ִ���?
	vector<int> dist(6, -1);


	queue<int> q;
	q.push(here);

	//���� ã�� ������ ���� ���
	discovered[here] = true;

	parent[here] = here;
	dist[here] = 0;
	//�ѹ� �� ��ĵ�� ���� �� �� �̻� ���ο� �߰� ������ ã�� ���� ���
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		//�湮 
		cout << "Visited : " << here << endl;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			dist[there] = dist[here] + 1;
		}


		/*int size = adjacent[here].size();

		for (int i = 0; i < size; i++)
		{
			int there = adjacent[here][i];

			//�̹� �߰ߵ� ������ ��� �н�
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

		}*/
	}

}

void BFSAll()
{
	discovered = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			BFS(i);
	}
}
void main()
{
	/*CreateGraph();

	visited = vector<bool>(6, false);
	DFS(0);*/

	CreateGraph();

	BFSAll();

}