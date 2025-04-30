#include "Tabl.h"
#include <iostream>
using namespace std;

Tabl::Tabl(int sz)
{
	position = m = new T[size = sz];
}

Tabl::~Tabl()
{
	clear();
	delete[] m;
}

T* Tabl::begin() { return m; }
T* Tabl::end() { return position; }
int Tabl::length() { return position - m; }
int Tabl::getSize() { return size; }

T* Tabl::insert(T* pos, const T& item)
{
	if (length() < size)
		*pos = item->copy();
	return pos + 1;
}

T* Tabl::erase(T* first, T* last)
{
	T* i;

	for (i = first; i < last; i++)
		*i = *(i + 1);
	position--;
	return first;
}
void Tabl::clear()
{
	position = begin();
}
int Tabl::remove(T* first, T* last, const T& item)
{
	T* i, * j = first;
	int n = 0;
	for (i = first; i < last; i++)
		if (!(*i)->equal(item))
			*j++ = *i;
		else
			n++;
	position = j;
	return n;
}
int Tabl::find(T* first, T* last, const T& item)
{
	T* i;
	for (i = first; i < last; i++)
		if ((*i)->equal(item))
			return i - m;

	return -1;
}
int Tabl::replace(T* first, T* last, const T& Old, const T& New)
{
	T* i;
	int count = 0;
	for (i = first; i < last; i++)
		if ((*i)->equal(Old))
		{
			(*i) = (New)->copy();
			count++;
		}
	return count;
}
void Tabl::sort(T* first, T* last)
{
	int i, j, len = last - first;

	for (j = 0; j < len - 1; j++)
		for (i = 0; i < len - 1 - j; i++)
			if (m[i]->cmp(m[i + 1]) > 0)
			{
				T tmp = m[i];
				m[i] = m[i + 1];
				m[i + 1] = tmp;
			}
}
int Tabl::Input(T buf)
{
	int count;
	position = begin();
	for (count = 0; count < getSize() && buf->input(); count++)
		position = insert(position, buf);

	return count;
}
void Tabl::Output()
{
	T* i;
	for (i = begin(); i != end(); i++)
		(*i)->output();
}