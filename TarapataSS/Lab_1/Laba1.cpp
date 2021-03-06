#include <cstring>
#include "pch.h"
#include <iostream>

using namespace std;
using T = int;


class Vector {
public:
	Vector(); 
	~Vector(); 
	Vector(unsigned size); 
	Vector(unsigned size, const T& val); 
	unsigned size(); 
	Vector(const Vector& vec);
	void resize(unsigned size);
	bool insert(unsigned pos, const T& val); 
	void push_back(const T& val); 
	bool contains(const T& val); 
	int& operator [](unsigned index); 
	int find(const T& val);
	T* data(); 
	Vector& operator =(const Vector& vec);
private:
	T *Data;
	unsigned newsize;

};


Vector::Vector() {
	Data = nullptr;
	newsize = 0;
}
Vector::~Vector() {
	delete[]Data;
}
Vector::Vector(unsigned Size) {
	newsize = Size;
	Data = new T[newsize];
	for (unsigned i = 0; i < newsize; i++) {
		Data[i] = T();

	}
}
Vector::Vector(unsigned Size, const T& val) {
	newsize = Size;
	Data = new T[newsize];
	for (unsigned i = 0; i < newsize; i++) {
		Data[i] = val;

	}
}
unsigned Vector::size() {
	return newsize;
}
Vector::Vector(const Vector& vec)
{
	newsize = vec.newsize;
	Data = new T[newsize];
	memcpy(Data, vec.Data, sizeof(T)*newsize);
}
void Vector::resize(unsigned Size) {
	T*newdata = Data;
	Data=new T[Size];
	memcpy(Data, newdata, sizeof(T)*newsize);
	if (Size > newsize) {
		for (unsigned i = newsize; i < Size; i++)
		{
			Data[i] = 0;
		}
	}
	newsize = Size;
	delete[]newdata;

}
bool Vector::insert(unsigned pos, const T& val) {
	if (pos <= newsize) {
		resize(newsize + 1);
		for (unsigned i = pos-1; i < newsize; i++)
		{
			Data[i] = Data[i - 1];		
		}	
		Data[pos-1] = val;
	return true;
	}
	else return false;
}
void Vector::push_back(const T& val) {
	resize(newsize + 1);
	Data[newsize-1] = val;
}
bool Vector::contains(const T& val) {
	for (unsigned i = 0; i < newsize; i++) {
		if (Data[i] == val) {
			return true;
		}
	}
	return false;
}
int& Vector::operator [](unsigned index) {
	return (Data[index]);
}
int Vector::find(const T& val) {
	for (unsigned i = 0; i < newsize; i++) {
		if (Data[i] == val) {
			return val;
		}
	}
	return -1;
}
T* Vector::data() {
	return Data;
}
Vector&Vector::operator =(const Vector&vec) 
{
	if (this != &vec)
	{
		newsize = vec.newsize;
		delete[]Data;
		Data = new int[newsize];
		memcpy(Data, vec.Data, sizeof(int)*newsize);
	}
	return*this;
}

int main()
{
	unsigned Size = 5;

	Vector vec (Size,3);

	cout << "Vector: " << endl;
	for (unsigned i = 0; i < Size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "Size of Vector: " << endl << vec.size() << endl;


	cout << "Result of Insert(1,8):"  << endl;
	vec.insert(3,8);
	for (unsigned i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	cout << "Result of Contains(1):" << endl << vec.contains(1) << endl;
	cout << "Result of Findings(3):" << endl << vec.find(3) << endl;

	vec.resize(10);
	cout << "Result of Resize(10):" << endl;
	for (unsigned i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	vec.push_back(7);
	cout << "Result of Push_back(7):" << endl;
	for (unsigned i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "Address search result:" << endl;
	cout << vec.data() << endl;
	cout << "Reference to an element of a vector by index(10):" << endl;
	cout<<vec.operator[](10);

	return 0;
}


