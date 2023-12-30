#pragma once
#include <assert.h>
class Vector
{

	using T = Pos;

public:
	/*explicit Vector(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Vector()
	{
		delete[] _buffer;
	}*/


	explicit Vector()
	{

	}
	~Vector()
	{
		if (_buffer)
		{
			delete[] _buffer;
		}
	}

	void push_back(const T& data)
	{
		//TODO
		if (_size == _capacity) {
			
			//증설작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
			{
				newCapacity++;
			}

			reserve(newCapacity);

		}

		_buffer[_size] = data; //데이터 저장

		//데이터 개수 증가
		_size++;
	}
	
	void pop_back()
	{


	}
	T& back()
	{
		return _buffer[_size - 1];
	}
	void clear()
	{
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}
	}

	void reserve(int capacity) //  인위적 증설작업
	{
		if (_capacity >= capacity)
		{
			return;
		}
		_capacity = capacity;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)//용량이 부족해진 배열에 있던 값들을 용량이 늘어난 배열에 채워넣는 역할
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
		{
			delete[] _buffer;//기존에 있던 배열 삭제
		}

		_buffer = newData; // 새로운 배열을 설정
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

