#include <iostream>
using namespace std;
#include <vector>
#include <queue>



template<typename T, typename Predicate = less<T>>
class PriorityQueue
{
private:
	//0(logN) 높이에 의존적이기 때문
	void push(const T& data)
	{
		_heap.push_back(data);

		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			//부모인덱스
			int next = (now - 1) / 2; 

			//부모 노드와 비교해 더 작으면 패배
			if (_heap[now] < _heap[next])
			{
				break;
			}

			//데이터 교체
			::swap(_heap[now],_heap[next]);
			now = next;

		}
	}
	//0(logN)
	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			//리프에 도달한 경우
			if (left >= (int)_heap.size())
			{
				break;
			}

			int next = now;

			//왼쪽값이 현재 값보다 크다면
			if (_heap[next] < _heap[left])
			{
				next = left;
			}

			//오른쪽이 현재 값보다 크다면
			if (right < _heap.size() && _heap[next] < _heap[right])
			{
				next = right;
			}

			//왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
			if (next == now)
			{
				break;
			}

			::swap(_heap[now], _heap[next]);
			now = next;
			
		}
	}

	T& top()
	{
		return _heap[0];
	}
	bool empty()
	{
		return _heap.empty();
	}
public:
	vector<T> _heap;
	Predicate _predicate;
};
void main()
{
	vector<int> v;
	priority_queue<int> pq;

	pq.push(10);
	pq.push(40);
	pq.push(30);
	pq.push(50);
	pq.push(20);

	int value = pq.top();
	pq.pop();

}