#include<iostream>
#include <conio.h>
using T = int;

using namespace std;

class Vector {
	T* data;
	unsigned Size;

public:
		Vector();						//��������� �����������
		Vector(unsigned size);			//������ ������ �������� size � ��������� ��� ���������� ����������, �.�. T()
		Vector(unsigned size, const T& val);	//������ ������ �������� size � ��������� ��� ��������� val
		unsigned size();				//���������� ������ �������
		void resize(unsigned size);		//������������ ������� ������� � size; ���� ����� ������ ������ ������� - ����� �������� ��������� ������
		bool insert(unsigned pos, const T& val);	//��������� val � ������� pos; ���������� true | false � ����������� �� ������ ��������
		void push_back(const T& val);	//��������� val � ����� �������
		bool contains(const T& val);	//���������� true ���� val ����������� � ������� � false � ��������� ������
		T& operator[](unsigned index);	// ��������� � �������� � �������� index. ��� ���� ������ ���� �������� ��� ������ ��������, ��� � �������� ���
		int find(const T& val);			//���������� ������ ������� ��������� val � ������ ��� -1 � ������ ��� ����������
		T* return_data();				//���������� ��������� �� ���������� �����
		Vector(const Vector&vec);		//copy-constructor
		Vector& operator=(const Vector&vec);	//assigment operator
		~Vector();						//destructor
};

Vector::Vector() {
	Size = 0;
	data = nullptr;
}

Vector::Vector(unsigned size) {
	Size = size;
	data = new T[size];
	for (unsigned i = 0; i < Size; i++) {
		data[i] = T();
	}
}

Vector::Vector(unsigned size, const T& val) {
	Size = size;
	data = new T[size];
	for (unsigned i = 0; i < size; i++) {
		data[i] = val;
	}
}



unsigned Vector::size() {
	return Size;
}

void Vector::resize(unsigned newsize) {
	T* temp = new T[newsize];
	if (newsize > Size) {
		memcpy(temp, data, sizeof(T) * Size);
		for (unsigned i = Size; i < newsize; i++) {
			temp[i] = 0;
		}
		delete[]data;
	}
	else {
		memcpy(temp, data, sizeof(T) * newsize);
		delete[]data;
	}
	Size = newsize;
	data = temp;
}

bool Vector::insert(unsigned pos, const T& val) {
	if (pos <= Size) {
		resize(Size + 1);
		for (unsigned i = Size-1; i > pos; i--) {
			data[i] = data[i-1];
		}
		data[pos] = val;
		return true;
	}
	else {
		return false;
	}
}

void Vector::push_back(const T& val) {
	insert(Size, val);
}

bool Vector::contains(const T& val) {
	for (unsigned i = 0; i < Size; i++) {
		if (val == data[i]) {
			return true;
		}
	}
	return false;
}

T& Vector::operator[](unsigned index) {
	return data[index];
}

int Vector::find(const T& val) {
	for (unsigned i = 0; i < Size; i++) {
		if (val == data[i]) {
			return i;
		}
	}
	return -1;
}

T* Vector::return_data() {
	return data;
}

Vector::Vector(const Vector&vec) {
	Size =vec.Size;
	data = new T[Size];
	memcpy(data, vec.data, sizeof(T)*Size);
}

Vector& Vector::operator =(const Vector&vec) {
	if (this != &vec) {
		Size = vec.Size;
		delete[]data;
		data = new T[Size];
		memcpy(data, vec.data, sizeof(T)*Size);
		return *this;
	}
}

Vector::~Vector() {
	Size = 0;
	delete[]data;
}

int main() {
	Vector vector1(10);
	Vector vector2(5, 2);
	cout <<"vector1 size: "<< vector1.size() << endl;
	cout << "vector1 : ";
	for (unsigned i = 0; i < vector1.size(); i++) {
		cout << vector1[i] << ' ';
	}
	cout << endl << "vector2 size: " << vector2.size() << endl;
	cout << "vector2 : ";
	for (unsigned i = 0; i < vector2.size(); i++) {
		cout << vector2[i] << ' ';
	}
	vector2.resize(11);
	cout << endl <<"vector2 resize" << vector2.size() << endl;
	vector2.insert(4, 3);
	cout << "vector2 insert (4,3)" << endl;
	for (unsigned i = 0; i < vector2.size(); i++) {
		cout << vector2[i] << ' ';
	}
	vector2.push_back(7);
	cout << endl << "push_back 7 in vector2"<<endl;
	for (unsigned i = 0; i < vector2.size(); i++) {
		cout << vector2[i] << ' ';
	}
	cout << endl <<"contains(7): " << vector2.contains(7) << "  contains(100): " << vector2.contains(100) <<endl;
	cout << "find(2): " << vector2.find(2) << "  find(9): " << vector2.find(9) << endl;
	vector2[5] = 13;
	cout << "vector2[5] = "  << vector2[5] <<endl;
	cout << "data : " << vector2.return_data() << endl;
	vector1 = vector2;
	cout << "vector1 = vector2 and vector 1 now :" << endl;
	for (unsigned i = 0; i < vector1.size(); i++) {
		cout << vector1[i] << ' ';
	}
	_getch();
	return 0;
}