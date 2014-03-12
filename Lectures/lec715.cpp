#include <iostream>
using namespace std;

int main()
{
	int x=10;
	int y=25;
	int *z=&x;
	int *q=&y;//declaring a pointer that points to a mem. adress
	int& a=*z;//dereferencing a pointer with *, declared with ampy
	int& b=*q;
	int* c = NULL;
	int* d = 0;
	int& e=*c;
	int& f=*d;


	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = &x = " << z << endl;
	cout << "q = &y = " << q << endl;
	cout << "a = *z = " << a << endl;
	cout << "b = *q = " << b << endl;
	cout << "c = null pointer = " << c << endl;
	cout << "d = null pointer = " << d << endl;
	cout << "e = *c = " << e << endl;
	cout << "f = *d = " << f << endl;






}