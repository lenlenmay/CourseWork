#include "AList.h"

// �������� ������� � �������� �������
template <class T>
Element<T>* List<T>::Move(int index)
{
    // 1. ���������� ��������� �� ������ ������
    Element<T>* t = begin;

    // 2. ���������� � ������� index
    for (int i = 0; i < index; i++)
        t = t->next;

    // 3. ������� ���������
    return t;
}

// �����, �������� ����� �� ������
template <class T>
void List<T>::Copy(const List<T>& obj)
{
    // 1. �������� ������ (���������� ������)
    Clear();

    // 2. ���� ����������� this <= obj
    Element<T>* t = obj.begin;

    while (t != nullptr)
    {
        AddEnd(t->data);
        t = t->next;
    }
}

// �����, ����������� ������������ ������� (�������) � ������
template <class T>
bool List<T>::CorrectIndex(int index)
{
    return (index >= 0) && (index < count);
}

// �����������
template <class T>
List<T>::List()
{
    // ������� ������ ������
    begin = end = nullptr;
    count = 0;
}

// ����������� �����������
template <class T>
List<T>::List(const List& obj)
{
    // ������� ����� �� ������
    Copy(obj);
}

// �������� �����������
template <class T>
List<T>& List<T>::operator=(const List& obj)
{
    Copy(obj);
    return *this;
}

// ����������
template <class T>
List<T>::~List()
{
    Clear(); // �������� ������
}

// �������� ������� ������ �� �������
template <class T>
T List<T>::GetElement(int index)
{
    // ��������, ��������� �� ������,
    // ���� ������ �� ���������, ������������� ����������
    if (!CorrectIndex(index))
        throw out_of_range("Incorrect index.");

    // ���� ������ ���������, �� ������� �������
    Element<T>* t = Move(index);
    return t->data;
}

// �������� �������� �������� � ��������� �������
template <class T>
void List<T>::SetElement(T _data, int index)
{
    // ��������, ��������� �� �������
    if (!CorrectIndex(index))
        return;

    // �������� ������� �� ������� � �������� ��� ��������
    Element<T>* t = Move(index);
    t->data = _data;
}

// �������� ������� � ����� ������
template <class T>
void List<T>::AddEnd(T _data)
{
    try
    {
        // 1. ������� ����� ������� � ������� _data
        Element<T>* t = new Element<T>;
        t->next = nullptr; // ���������� �������� ���
        t->prev = end; // ���������� ���������� �������
        t->data = _data; // �������� ������

        // 2. ��������� ���� next ���� ��� ���������� ��������
        if (end != nullptr)
            end->next = t;

        // 3. ��������, ���� �� � ������ ��������
        if (count == 0)
        {
            // ���� ��������� ���,
            // �� ��� ������������ � ������ � ����� ������
            begin = end = t;
        }
        else
        {
            // ���� �������� � ������ ����, �� ��� ����� ������
            end = t;
        }

        // 3. ��������� ����� ���������� ���������
        count++;
    }
    catch (bad_alloc e)
    {
        // ���� ������ �� ��������, �� ������� ��������� ���������
        cout << e.what() << endl;
    }
}

// �������� ������� � ������ ������
template <class T>
void List<T>::AddBegin(T _data)
{
    try
    {
        // 1. ������� ����� ������� (����� ������ ������)
        // � ��������� ��� �������
        Element<T>* t = new Element<T>;
        t->data = _data; // ������
        t->prev = nullptr; // ����������� �������� ���

        // ��������� ������� ��������� �� ���������� ������
        t->next = begin;

        // 2. ���� �� �������� � ������?
        if (count > 0)
        {
            // ���� ����, �� ������������� ���������� ������ ������
            begin->prev = t;
            begin = t;
        }
        else
        {
            // ���� ��������� ���, �� ������ � ����� ���� ��� ����� ���������
            begin = end = t;
        }

        // 3. ��������� ����� ���������� ���������
        count++;
    }
    catch (bad_alloc e)
    {
        // ���� ������ �� ��������, �� ���������� ������
        cout << e.what() << endl;
    }
}

// ������� �������� � �������� ������� ������
template <class T>
void List<T>::Insert(T _data, int index)
{
    // 1. ��������, ��������� �� �������
    if (!CorrectIndex(index))
        return;

    // 2. ��������, ������� �� � ����� ������ (�� ��������� end)
    if (index == count)
    {
        // �������� ������ �� ��������� end
        AddEnd(_data);
        return;
    }

    // 3. ��������, ������� �� � ������ ������ (����� begin)
    if (index == 0)
    {
        AddBegin(_data);
        return;
    }

    try
    {
        // 4. �������� ������� ����� �������� �������
        Element<T>* itemPrev = Move(index - 1);

        // 5. �������� ������� � ������� �������
        Element<T>* item = Move(index);

        // 6. ������� ����� ������� � �������� ��� � ������
        Element<T>* t = new Element<T>;
        t->data = _data;
        t->next = item;
        t->prev = itemPrev;
        itemPrev->next = t;
        item->prev = t;

        // 7. ��������� ���������� ���������
        count++;
    }
    catch (bad_alloc e)
    {
        // ���� ������ �� ��������, �� ������� ��������� ���������
        cout << e.what() << endl;
    }
}

// ������� ������� � �������� �������,
// ������� ���������� � 0
template <class T>
void List<T>::Del(int index)
{
    // 1. ��������, ���� �� �������� � ������
    if (count == 0) return;

    // 2. �����, ���� ������� ������� �����������
    if (!CorrectIndex(index))
        return;

    // 3. ������� � ���������� ��������
    Element<T>* item = Move(index);

    // 4. �������� ���������� �������
    Element<T>* itemPrev = item->prev;

    // 5. �������� ��������� �������
    Element<T>* itemNext = item->next;

    // 6. ��������, ��������� �� �� ������ ������� ������
    if ((count > 1) && (itemPrev != nullptr))
        itemPrev->next = itemNext; // ������ ������� item

      // 7. ��������, ��������� �� �� ��������� ������� ������
    if ((itemNext != nullptr) && (count > 1))
        itemNext->prev = itemPrev;

    // 8. ���� ��������� ������ �������
    if (index == 0)
        begin = itemNext;

    // 9. ���� ��������� ��������� �������
    if (index == count - 1)
        end = itemPrev;

    // 10. ������� ������� item
    delete item;

    // 11. ��������� ����� ���������� ���������
    count--;
}

// ������� ������
template <class T>
void List<T>::Clear()
{
    // ����� count ��� ������� ������ ������� ������
    int n = count; // ������� ����� �� count - �����!
    for (int i = 0; i < n; i++)
        Del(0);
}

// �������������� ������
template <class T>
void List<T>::Reverse()
{
    List<T> L;
    Element<T>* t = begin;

    // ���� ������������ ������,
    // ������� ����������� � ������ ������
    while (t != nullptr)
    {
        L.AddBegin(t->data);
        t = t->next;
    }
    *this = L;
}

// ����� ������
template <class T>
void List<T>::Print(string msg)
{
    cout << msg << " => ";

    Element<T>* t = begin;
    for (int i = 0; i < count; i++)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

// �������� ���������� ��������� ������
template <class T>
int List<T>::Count()
{
    return count;
}

// �������� + - ������������ �������
template <class T>
List<T>& List<T>::operator+(const List<T>& obj)
{
    // 1. �������� ������ � ������ obj
    Element<T>* t = obj.begin;

    // 2. �������� � ���������� ������ �������� t
    while (t != nullptr)
    {
        AddEnd(t->data);
        t = t->next;
    }

    // 3. ������� ������������ ������
    return *this;
}

// �������� ��������� ������� �� ���������
template <class T>
bool List<T>::operator==(const List<T>& obj)
{
    // 1. ������� �������� ������� �������
    if (count != obj.count)
        return false;

    // 2. ���� ������� ���������, �� �������� �����������
    Element<T>* t1 = begin;
    Element<T>* t2 = obj.begin;

    while (t1 != nullptr)
    {
        // ��� ������ ������� ���� �� ���� ������������, �� ����� � ����� false
        if (t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}