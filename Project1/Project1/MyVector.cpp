#include "MyVector.h"

MyVector::MyVector()
{
	capacity = 0;
	size = 0;
	ar = new int[0];
}

MyVector::MyVector(int n):MyArray(n), capacity(n)
{
}

MyVector::MyVector(int n, int value)
{
	size = n;
	capacity = n;
	ar = new int[capacity];
	for (int i = 0; i < n; i++) {
		ar[i] = value;
	}
}

MyVector::MyVector(const MyVector & vec)
{
	size = vec.size;
	capacity = vec.capacity;
	this->ar = new int[capacity];
	for (int i = 0; i < size; i++) {
		this->ar[i] = vec.ar[i];
	}
}

int MyVector::getCapacity() const
{
	return this->capacity;
}

void MyVector::addCapacity(int n)
{
	capacity += n;
	int *arr = new int[capacity];
	for (int i = 0; i < size - n; i++) {
		arr[i] = this->ar[i];
	}
	for (int i = size - n; i < capacity; i++) {
		arr[i] = 0;
	}
	delete[]this->ar;
	this->ar = arr;
}

void MyVector::pushBack(int val)
{
	if (size < capacity) {
		this->ar[size] = val;
	}
	else {
		capacity++;
		int *arr = new int[capacity];
		for(int i = 0; i < size; i++) {
			arr[i] = this->ar[i];
		}
		arr[size] = val;
		size++;
		this->ar = arr;
	}
}

int MyVector::popBack()
{
	size--;
	return ar[size + 1];
}

void MyVector::insert(int index, int val)
{
	if (index < capacity) {

	}
}

int MyVector::remove(int index)
{
	return 0;
}

MyVector & MyVector::operator=(const MyVector & vec)
{
	// TODO: вставьте здесь оператор return
}
