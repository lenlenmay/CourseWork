#pragma once

#include <iostream>
using namespace std;

// ���������, ����������� ���� ������� (����)
template <class T>
struct Element
{
	// ������������ ��������� Element<T>
	T data; // ������
	Element<T>* next; // ����� ���������� �������� � ������
	Element<T>* prev; // ����� ����������� �������� � ������
};

// ����c, ����������� ���������� ������
template <class T>
class List
{
private:
	Element<T>* begin; // ��������� �� ������ ������� ������
	Element<T>* end; // ��������� �� ��������� ������� ������
	int count; // ���������� ��������� � ������
	
	// �����, ������������ ������� � �������� �������,
	//��������� ��� ������� ���������.
	Element<T>* Move(int index);

	// �����, ���������� ������
	void Copy(const List<T>& obj);

	// �����, ����������� ������������ ������ (�������) � ������
	bool CorrectIndex(int index);

public:
	// �����������
	List();

	// ����������� �����������
	List(const List& obj);

	// �������� �����������
	List<T>& operator=(const List& obj);

	// ����������
	~List();

	// ---------- ������ ������� � ��������� ��������� ������ --------
	// �������� ������� ������ �� �������
	T GetElement(int index);

	// �������� �������� �������� � �������� �������
	void SetElement(T _data, int index);

	// ---------- ������ ��������� ������� ������ ------------
	// �������� ������� � ����� ������
	void AddEnd(T _data);

	// �������� ������� � ������ ������
	void AddBegin(T _data);

	// ������� �������� � �������� ������� ������
	void Insert(T _data, int index);

	// ������� ������� � �������� �������,
	// ������� ���������� � 0
	void Del(int index);

	// ������� ������
	void Clear();

	// �������������� ������
	void Reverse();

	// ����� ������
	void Print(string msg);

	// �������� ���������� ��������� ������
	int Count();

	// ------------------------------------------
	// ���������� ����������
	// �������� + - ������������ �������
	List<T>& operator+(const List<T>& obj);

	// �������� ��������� ������� �� ���������
	bool operator==(const List& obj);
};