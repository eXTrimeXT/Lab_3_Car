#pragma once
#include "stdio.h"
#include "MyDate.h"
#include "MyString.h"
class Car
{
	MyString marka;
	MyString company;
	MyDate the_date;
	int id;
	double price;
public:
	Car();
	Car(const Car&);
	Car(char* m1, char* m2, int d, int m, int y, int sc, double pr);
	Car* copy();
	int cmp(Car* t);
	int equal(Car* t);
	int input();
	void output();
};