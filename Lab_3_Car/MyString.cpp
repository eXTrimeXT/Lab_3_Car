#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	s = new char[1];
	*s = '\0';
	len = 0;
}
MyString::MyString(char* t)
{
	s = new char[strlen(t) + 1];
	*s = '\0';
	strcpy(s, t);
	len = strlen(t);
}
MyString::MyString(const MyString& u)
{
	s = new char[u.len + 1];
	*s = '\0';
	strcpy(s, u.s);
	len = u.len;
}
MyString::~MyString()
{
	delete[] s;
}
char& MyString::item(int t)
{
	char err = 'e';
	if (t <= len && t >= 0) return s[t];
	else cout << "Error.";
	return err;
}
MyString* MyString::copy()
{
	return new MyString(*this);
}
void MyString::assign(const MyString& u)
{
	s = new char[u.len + 1];
	*s = '\0';
	strcpy(s, u.s);
	len = u.len;
}
int MyString::cmp(const MyString& t)
{
	return strcmp(s, t.s);
}
int MyString::equal(const MyString& t)
{
	return strcmp(s, t.s) == 0;
}
int MyString::input()
{
	if (cin.eof()) return 0;
	cin >> *this;
	return 1;
}
int MyString::output()
{
	cout << *this << endl;
	return 0;
}

MyString& MyString::operator=(const MyString& t)
{
	if (this == &t) return *this;
	delete[]s;
	s = new char[(len = t.len) + 1];
	strcpy(s, t.s);
	return *this;
}
MyString::operator char* ()
{
	char* p = new char[len + 1];
	strcpy(p, s);
	return p;
}
int operator == (const MyString& a, const MyString& b)
{
	return (strcmp(a.s, b.s));
}
char& MyString::operator[](int i)
{
	if (i > 0 && i <= len) return s[i];
	cout << "Index error"; exit(1);
}
MyString& MyString::operator+=(const MyString& t)
{
	char* p = new char[len = (len + t.len) + 1];
	strcpy(p, s); strcat(p, t.s);
	delete[]s; s = p;
	return *this;
}
MyString& operator +(const MyString& a, const MyString& b)
{
	MyString tmp = a;
	tmp += b;
	return tmp;
}
ostream& operator<<(ostream& os, const MyString& ms)
{
	os << ms.s;
	return os;
}
istream& operator>>(istream& is, MyString& ms)
{
	char buf[256];
	is.getline(buf, 254, '\n');
	ms = buf;
	return is;
}