#include "Containers.h"
#include <iostream>
using namespace std;
MyArray::MyArray()
{
	size = 0;
	ar = NULL;
}

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < n; i++) {
		ar[i] = 0;
	}
}

MyArray::MyArray(const MyArray & ar) 
{
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < ar.size; i++) {
		this->ar[i] = ar.ar[i];
	}
}

int MyArray::getSize() const
{
	for (int i = getCapacity() - 1; i >= 0; i--) {
		if (ar[i] != 0)
			return (i + 1);
	}
	return 0;
}

int MyArray::getCapacity() const
{
	return this->size;
}

void MyArray::show() const
{
	for (int i = 0; i < getCapacity(); i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

void MyArray::addCapacity(int n)
{
	size += n;
	int *arr = new int[size];
	for (int i = 0; i < size-n; i++) {
		arr[i] = this->ar[i];
	}
	for (int i = size - n; i < size; i++) {
		arr[i] = 0;
	}
	delete[]this->ar;
	this->ar = arr;
}

int & MyArray::operator[](int index) 
{
	return  ar[index];
}

MyArray & MyArray::operator=(const MyArray & ar)
{
	if (this == &ar) {
		return *this;
	}
	size = ar.size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = ar.ar[i];
	}
	delete[]this->ar;
	this->ar = arr;
}

MyArray::~MyArray()
{
	delete[] ar;
	size = NULL;
}

Container::~Container()
{
	size = NULL;
}
