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

	priority_queue<int, vector<int>, greater<int>> pq;

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

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	//哭率捞 刚历 场车促搁
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}


void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;

	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);
	MergeResult(v,left,mid,right);
}

int main()
{
	vector<int> v{ 1,5,3,4,2 };
	MergeSort(v, 0, v.size() - 1);
}
