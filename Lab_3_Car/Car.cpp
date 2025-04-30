#include "Car.h"
#include "MyString.h"
#include "MyDate.h"
#include <iostream>
#include <string.h>
using namespace std;

Car::Car()
{
	price = 0;
	id = 0;
}
Car::Car(char* m1, char* m2, int d, int m, int y, int sc, double pr) : marka(m1), company(m2), the_date(d, m, y), id(sc), price(pr) {}

Car::Car(const Car& s) : marka(s.marka), the_date(s.the_date), company(s.company), id(s.id), price(s.price) {}
Car* Car::copy()
{
	return new Car(*this);
}
int Car::cmp(Car* t)
{
	if (marka.cmp(t->marka) != 0)
		return marka.cmp(t->marka);
	else if ((price - t->price) != 0)
		return price - t->price;
	else if ((id - t->id) != 0)
		return id - t->id;
	else if (company.cmp(t->company) != 0)
		return company.cmp(t->company);
	else
		return the_date.cmp(t->the_date);
}
int Car::equal(Car* t)
{
	return (
		(marka.equal(t->marka)) &&
		((price == t->price)) &&
		((id == t->id)) &&
		(company.equal(t->company)) &&
		(the_date.equal(t->the_date)));

}
int Car::input()
{
	static int count;
	char endline;
	cout.width(10);
	cout << "marka "; marka.input();
	if (cin.eof()) return 0;
	cout.width(10);
	cout << "company "; company.input();
	cout << "The date ";	the_date.input();
	cout.width(10);
	cout << "id "; cin >> id;
	cin.get(endline);
	cout.width(10);
	cout << "price ";	cin >> price;
	cin.get(endline);
	if (!cin.eof())
	{
		cout << "-----------------" << count++ << "\n";
		return 1;
	}
	return 0;
}
void Car::output()
{
	static int count;
	if (!count++)
	{
		cout.widen(35); cout << "marka" << "\t";
		cout.widen(15); cout << "company" << "\t";
		cout.widen(8); cout << "The date" << "\t";
		cout.widen(8); cout << "id" << "\t";
		cout.widen(8); cout << "price" << "\n";
	}
	cout.widen(35); marka.output(); cout << "\t";
	cout.widen(15); company.output(); cout << "\t";
	cout.widen(8); the_date.output();
	cout.widen(8); cout << id << "\t";
	cout.widen(8); cout << price << "\t";
	cout << "\n";
}