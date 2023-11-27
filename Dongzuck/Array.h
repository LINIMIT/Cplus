#pragma once
#include <assert.h>
class Array
{

	using T = int;

public:
	explicit Array(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Array()
	{
		delete[] _buffer;
	}

	void push_back(const T& data)
	{
		//TODO
		if (_size == _capacity) {
			return;
		}
		_buffer[_size] = data;
		_size++;
	}

	T& operator[](int index) //배열에서의 arr[1] 과 같은 []역할을 만들어줌 동적배열은 기존에 존재하던 파일X
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];//해당 인덱스에 존재하는 어떤 값을 출력해줌 
	};
	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0; //채워진 배열의 크기
	int  _capacity = 0;//동적 배열의 전체 크기
};

