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
			
			//�����۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
			{
				newCapacity++;
			}

			reserve(newCapacity);

		}

		_buffer[_size] = data; //������ ����

		//������ ���� ����
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

	void reserve(int capacity) //  ������ �����۾�
	{
		if (_capacity >= capacity)
		{
			return;
		}
		_capacity = capacity;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)//�뷮�� �������� �迭�� �ִ� ������ �뷮�� �þ �迭�� ä���ִ� ����
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
		{
			delete[] _buffer;//������ �ִ� �迭 ����
		}

		_buffer = newData; // ���ο� �迭�� ����
	}

	T& operator[](int index) //�迭������ arr[1] �� ���� []������ ������� �����迭�� ������ �����ϴ� ����X
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];//�ش� �ε����� �����ϴ� � ���� ������� 
	};


	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0; //ä���� �迭�� ũ��
	int  _capacity = 0;//���� �迭�� ��ü ũ��
};

