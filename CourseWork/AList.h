#pragma once

#include <iostream>
using namespace std;

// Структура, описывающая один элемент (узел)
template <class T>
struct Element
{
	// Составляющие структуры Element<T>
	T data; // данные
	Element<T>* next; // адрес следующего элемента в списке
	Element<T>* prev; // адрес предыдущего элемента в списке
};

// Класc, реализующий двусвязный список
template <class T>
class List
{
private:
	Element<T>* begin; // указатель на первый элемент списка
	Element<T>* end; // указатель на последний элемент списка
	int count; // количество элементов в списке
	
	// Метод, возвращающий элемент в заданной позиции,
	//считается что позиция корректна.
	Element<T>* Move(int index);

	// Метод, копирующий список
	void Copy(const List<T>& obj);

	// Метод, проверяющий корректность позиии (индекса) в списке
	bool CorrectIndex(int index);

public:
	// Конструктор
	List();

	// Конструктор копирования
	List(const List& obj);

	// Оператор копирования
	List<T>& operator=(const List& obj);

	// Деструктор
	~List();

	// ---------- Методы доступа к отдельным элементам списка --------
	// Получить элемент списка по индексу
	T GetElement(int index);

	// Изменить значение элемента в заданной позиции
	void SetElement(T _data, int index);

	// ---------- Методы изменения размера списка ------------
	// Добавить элемент в конец списка
	void AddEnd(T _data);

	// Добавить элемент в начало списка
	void AddBegin(T _data);

	// Вставка элемента в заданную позицию списка
	void Insert(T _data, int index);

	// Удалить элемент в заданной позиции,
	// позиция нумеруется с 0
	void Del(int index);

	// Очистка списка
	void Clear();

	// Реверсирование списка
	void Reverse();

	// Вывод списка
	void Print(string msg);

	// Получить количество элементов списка
	int Count();

	// ------------------------------------------
	// Перегрузка операторов
	// Операция + - конкатенация списков
	List<T>& operator+(const List<T>& obj);

	// Операция сравнения списков на равенство
	bool operator==(const List& obj);
};