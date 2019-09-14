#include "Containers.h"
#include <iostream>
using namespace std;
MyArray::MyArray()
{
	ar = new int[size];
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
	return this->size;
}

int MyArray::getCapacity() const
{
	return this->size;
}

void MyArray::show() const
{
	for (int i = 0; i < size; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

void MyArray::addCapacity(int n)
{
	size += n;
	ar = new int[size];
	for (int i = 0; i < size; i++) {
		this->ar[i] = ar[i];
	}
}

int & MyArray::operator[](int index)
{
	return  ar[index];
}

MyArray & MyArray::operator=(const MyArray & ar)
{
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
}

Container::~Container()
{
	size = NULL;
}
