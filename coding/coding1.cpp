#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//다익스트라(가중치)

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;


void CreateGraph()
{
	vertices.resize(6);

	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[5][4] = adjacent[4][5] = 5;
}

struct VertexCost
{
	VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) {}

	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const VertexCost& other) const
	{
		return cost > other.cost;
	}


	int cost;
	int vertex;
};
void Dijikstra(int here)
{
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	pq.push(VertexCost(0, here));
	best[here] = 0;
	parent[here] = here;

	while (pq.empty() == false)
	{
		//제일 좋은 후보 고르기
		VertexCost v = pq.top();
		pq.pop();

		int cost = v.cost;
		here = v.vertex;

		//더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost)
			continue;

		cout << "방문!" << here << endl;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
				continue;


			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[here])
				continue;

			best[there] = nextCost;
			parent[there] = here;
			pq.push(VertexCost(nextCost, there));

		}
	}

}
int main()
{
	CreateGraph();

	Dijikstra(0);

}