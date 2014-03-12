#include <iostream>
using namespace std;
	void zaniness (int* q, int z)
	{
		*q = 23;
		z = 37;
		cout<< *q << endl;
		cout << z << endl;
	}
	//   (int &a) = pass by reference
	//   (int* &a) = pass POINTER by reference
	void wackiness (int* ptr, int address)
	{
		ptr = &address;
		cout <<ptr << endl;
	}

	void hey(int* &a)
	{
		*a=69;
		cout << *a << endl;
		// a=NULL;

	}

	void passbyref( int a, int &b)
	{
		a=30;
		b =6969;
	}


int main()
{
	int x = 7;
	int y = 5;
	int z = 55;

	int* ptr1= &x;
	int* ptr2= &y;
	int* ptr3;
	int* ptr4 = &z;
	int garbage;

	// cout << garbage << endl;
	cout << x << endl;
	cout << y << endl;

	cout <<ptr1 <<endl;
	cout <<ptr2<< endl;


	zaniness(ptr1, y);
	cout << ptr1 << endl;
	cout << *ptr1 << endl;
	cout << y << endl;

	cout <<"Wackiness: " <<ptr3 << endl;
	wackiness(ptr3, x);
	cout << ptr3 << endl;

	cout << ptr4 << endl;
	cout << *ptr4 << endl;

	hey (ptr4);

	cout << ptr4 << endl;
	if (ptr4 == NULL){ cout << "ptr4 is NULL" << endl;}
	else {cout <<ptr4 << endl;}

	cout<<*ptr4<<endl;

	cout << "\n" << endl;
	cout << x <<", " << y << endl;
	passbyref(x, y);
	cout << x <<", " << y << endl;

}


