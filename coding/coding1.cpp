#include <iostream>
using namespace std;
#include <vector>
#include <queue>



template<typename T, typename Predicate = less<T>>
class PriorityQueue
{
private:
	//0(logN) ���̿� �������̱� ����
	void push(const T& data)
	{
		_heap.push_back(data);

		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			//�θ��ε���
			int next = (now - 1) / 2; 

			//�θ� ���� ���� �� ������ �й�
			if (_heap[now] < _heap[next])
			{
				break;
			}

			//������ ��ü
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

			//������ ������ ���
			if (left >= (int)_heap.size())
			{
				break;
			}

			int next = now;

			//���ʰ��� ���� ������ ũ�ٸ�
			if (_heap[next] < _heap[left])
			{
				next = left;
			}

			//�������� ���� ������ ũ�ٸ�
			if (right < _heap.size() && _heap[next] < _heap[right])
			{
				next = right;
			}

			//����/������ �� �� ���� ������ ������ ����
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