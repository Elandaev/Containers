#include "MyVector.h"

MyVector::MyVector()
{
	capacity = 0;
	size = 0;
	ar = new int[0];
}

MyVector::MyVector(int n):MyArray(n), capacity(n)
{
	size = 0;
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
	size = vec.getSize();
	capacity = vec.capacity;
	this->ar = new int[capacity];
	for (int i = 0; i < getCapacity(); i++) {
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
	for (int i = 0; i < this->size; i++) {
		arr[i] = this->ar[i];
	}
	for (int i = this->size; i < capacity; i++) {
		arr[i] = 0;
	}
	delete[]this->ar;
	this->ar = arr;
}

void MyVector::pushBack(int val)
{
	if (getSize() < capacity) {
		this->ar[getSize()] = val;
	}
	else {
		capacity++;
		int *arr = new int[capacity];
		for(int i = 0; i < getSize(); i++) {
			arr[i] = this->ar[i];
		}
		arr[getSize()] = val;
		size++;
		this->ar = arr;
	}
}

int MyVector::popBack()
{
	size--;
	int tmp = ar[getSize() - 1];
	ar[getSize() - 1] = 0;
	return tmp;
}

void MyVector::insert(int index, int val)
{
	if (index < capacity && getSize() < capacity) {
		for (int i = getSize(); i > index; i--) {
			this->ar[i] = ar[i - 1];
		}
		this->ar[index] = val;
	}
	else {
		capacity = index;
		int *arr = new int[capacity];
		for (int i = 0; i < getSize(); i++) {
			arr[i] = this->ar[i];
		}
		for (int i = getSize(); i < capacity - 1; i++) {
			arr[i] = 0;
		}
		arr[capacity] = val;
		this->ar = arr;
	}
}

int MyVector::remove(int index)
{
	int tmp = this->ar[index];
	for (int i = index; i < capacity - 1; i++) {
		this->ar[i] = this->ar[i + 1];
	}
	return tmp;
}

MyVector & MyVector::operator=(const MyVector & vec)
{
	if (this == &vec) {
		return *this;
	}
	size = vec.getSize();
	capacity = vec.capacity;
	int *arr = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = vec.ar[i];
	}
	delete[]this->ar;
	this->ar = arr;
}
