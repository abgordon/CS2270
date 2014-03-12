#include <iostream>
using namespace std;

int main()
{
	char* array1 = new char [5];
	char* array2 = new char [5];

	char int1=1;
	char int2=2;
	char int3='1';
	char int4='2';

	cout << int1+int2 << endl;
	cout << int3+int4 << endl;

	array1[3] = 4;
	array2[3] = 4;
	array1[4] = '4';
	array2[4] = '4';
	cout << array1[3] << endl;
	cout << array2[3] << endl;
	cout << array1[4] << endl;
	cout << array2[4] << endl;

	cout << array1[3] + array2[3] <<endl;
	cout << array1[4] + array2[4] <<endl;



}