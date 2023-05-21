#pragma once

#include <iostream>
using namespace std;


template <class T>
struct Element
{

	T data;
	Element<T>* next;
	Element<T>* prev;
};


template <class T>
class List
{
private:
	Element<T>* begin;
	Element<T>* end; 
	int count;
	
	

	Element<T>* Move(int index)
	{
		Element<T>* t = begin;

		for (int i = 0; i < index; i++)
			t = t->next;

		return t;
	};


	void Copy(const List<T>& obj)
	{
		Clear();

		Element<T>* t = obj.begin;

		while (t != nullptr)
		{
			AddEnd(t->data);
			t = t->next;
		}
	};


	bool CorrectIndex(int index)
	{
		return (index >= 0) && (index < count);
	};

public:

	List()
	{
		begin = end = nullptr;
		count = 0;
	};


	List(const List& obj)
	{
		Copy(obj);
	};

	List<T>& operator=(const List& obj)
	{
		Copy(obj);
		return *this;
	};

	~List()
	{
		Clear(); 
	};

	T GetElement(int index)
	{
		if (!CorrectIndex(index))
			throw out_of_range("Incorrect index.");

		Element<T>* t = Move(index);
		return t->data;
	};

	void SetElement(T _data, int index)
	{
		if (!CorrectIndex(index))
			return;

		Element<T>* t = Move(index);
		t->data = _data;
	};

	void AddEnd(T _data)
	{
		try
		{
			Element<T>* t = new Element<T>;
			t->next = nullptr; 
			t->prev = end; 
			t->data = _data;

			if (end != nullptr)
				end->next = t;

			if (count == 0)
			{
				begin = end = t;
			}
			else
			{
				end = t;
			}

			count++;
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}
	};

	void AddBegin(T _data)
	{
		try
		{
			Element<T>* t = new Element<T>;
			t->data = _data; 
			t->prev = nullptr; 

			t->next = begin;

			if (count > 0)
			{
				begin->prev = t;
				begin = t;
			}
			else
			{
				begin = end = t;
			}

			count++;
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}
	};

	void Insert(T _data, int index)
	{
		if (!CorrectIndex(index))
			return;

		if (index == count)
		{
			AddEnd(_data);
			return;
		}

		if (index == 0)
		{
			AddBegin(_data);
			return;
		}

		try
		{
			Element<T>* itemPrev = Move(index - 1);

			Element<T>* item = Move(index);

			Element<T>* t = new Element<T>;
			t->data = _data;
			t->next = item;
			t->prev = itemPrev;
			itemPrev->next = t;
			item->prev = t;

			count++;
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}
	};

	void Del(int index)
	{
		if (count == 0) return;

		if (!CorrectIndex(index))
			return;

		Element<T>* item = Move(index);

		Element<T>* itemPrev = item->prev;

		Element<T>* itemNext = item->next;

		if ((count > 1) && (itemPrev != nullptr))
			itemPrev->next = itemNext; 

		if ((itemNext != nullptr) && (count > 1))
			itemNext->prev = itemPrev;

		if (index == 0)
			begin = itemNext;

		if (index == count - 1)
			end = itemPrev;

		delete item;

		count--;
	};


	void UpdateData(T _data, int index)
	{
		Insert(_data, index);
		Del(index + 1);
	};

	void Clear()
	{
		int n = count; 
		for (int i = 0; i < n; i++)
			Del(0);
	};

	void Reverse()
	{
		List<T> L;
		Element<T>* t = begin;

		while (t != nullptr)
		{
			L.AddBegin(t->data);
			t = t->next;
		}
		*this = L;
	};

	void Print(string msg)
	{
		cout << msg << " => ";

		Element<T>* t = begin;
		for (int i = 0; i < count; i++)
		{
			cout << t->data << " ";
			t = t->next;
		}
		cout << endl;
	};

	int Count()
	{
		return count;
	};

	List<T>& operator+(const List<T>& obj)
	{
		Element<T>* t = obj.begin;

		while (t != nullptr)
		{
			AddEnd(t->data);
			t = t->next;
		}

		return *this;
	};

	T operator[](int index)
	{
		return GetElement(index);
	};

	bool operator==(const List& obj)
	{
		if (count != obj.count)
			return false;

		Element<T>* t1 = begin;
		Element<T>* t2 = obj.begin;

		while (t1 != nullptr)
		{
			if (t1->data != t2->data)
				return false;

			t1 = t1->next;
			t2 = t2->next;
		}

		return true;
	};
};