#include "Car.h"
typedef Car* T;

class Tabl
{
	T* m;
	T* position;
	int size;
public:
	Tabl(int sz);
	~Tabl();
	T* begin();
	T* end();
	int length();
	int getSize();
	T* insert(T* pos, const T& item);
	T* erase(T* first, T* last);
	void clear();
	int remove(T* first, T* last, const T& item);
	int find(T* first, T* last, const T& item);
	int replace(T* first, T* last, const T& Old, const T& New);
	void sort(T* first, T* last);
	int Input(T buf);
	void Output();
};