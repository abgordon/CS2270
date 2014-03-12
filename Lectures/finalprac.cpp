#include <iostream>
using namespace std;


void funRecurse(int funParam)
{
	if (funParam<35)
	{
	cout<< "Are you also"<<endl;
	return;
	}
	funRecurse(funParam/10);
	cout << "Sick ofthis"<<endl;
	funRecurse(funParam/30);
	cout<<"Summer Class Too?"<<endl;
}

template <typename Item>
void myfunction(Item& x, Item& y)
{
	x = x * 23;
	y = y * 13;
}

void moreorless(int* &p)
{
	p = NULL;
}


int main()
{
	funRecurse(300);


	const double*c;

	double d = 6969.6966969;
	c=&d;
	cout << c << endl;
	cout << *c << endl;
	// *c = 0.0;
	// cout << *c <<endl;


	// double f = 500.696996;
	// c=&f;
	// cout << c << endl;

	// cout <<d<<endl;
	// cout <<f<<endl;
	// myfunction(d,f);
	// cout <<d<<endl;
	// cout <<f<<endl;


	int* x;
	int y = 69;
	x=&y;

	cout << "x = " << x << endl;
	cout <<"y = " << y << endl;


	moreorless(x);
	cout <<"y = " << y << endl;
	cout << "x = " << x << endl;


}















