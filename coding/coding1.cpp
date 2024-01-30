#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <map>
#include <algorithm>

void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	for (auto i = 0; i < n - 1; i++)
	{
		for (auto j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

void SelectionSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIndex])
				bestIndex = j;
		}
		if (i != bestIndex)
		{
			swap(v[i], v[bestIndex]);
		}

	}
}

void HeapSort(vector<int>& v)
{

	priority_queue<int,vector<int>,greater<int>> pq;

	// 0(NlogN)
	for (int num : v)
		pq.push(num); //logN

	v.clear();

	//0(NlogN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top()); // 0(1)
		pq.top();//0(logN)
	}

}

int main()
{
	vector<int> v{ 1,5,3,4,2 };
	HeapSort(v);
}
