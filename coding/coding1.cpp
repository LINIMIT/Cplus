#include <iostream>
using namespace std;
#include <vector>
#include <queue>


//���� ����Ʈ ���
void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex>  v(6);

	//2���� ����
	vector<vector<int>> adjacent;
	adjacent.resize(6);

	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };


	//0-3 ����Ȯ��
	bool connected = false;

	int size = adjacent[0].size();
	for (int i = 0; i < size; i++)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
		{
			connected = true; // �������� Ȯ��

		}
	}
}


//���� ��� ���
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

	//6���� ���͸� ����� �� ������ �ȿ� X(false)�� �־���
	//adjacent[from][to]
	//�޸� �Ҹ� ��������, ���� ����
	//���� ����Ʈ�� ������ �˻��ؾ������� ��� ��Ŀ����� �׳� �ε����� �˻��ϸ��
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	//0-3 ����Ȯ��
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