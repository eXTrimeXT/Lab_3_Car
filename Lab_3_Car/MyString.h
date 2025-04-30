#pragma once
#include "iostream"
using namespace std;
class MyString 
{
	char* s;
	int len;
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&);
	int input();
	int output();
	MyString& operator=(const MyString&);
	operator char* ();
	friend int operator == (const MyString&, const MyString&);
	char& operator[](int i);
	MyString& operator +=(const MyString&);
	friend MyString& operator + (const MyString&, const MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);
};