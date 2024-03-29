#include <iostream>
#include <cstdlib> 
#include <cstring>
#include "bigInt.h" 
#include "bigInt.cpp" 

using namespace std;

int main()
{
	//test the default constructor
	bigInt x;
	cout<<"\n***DEFAULT CONSTRUCTOR TEST***\n";
	cout<<"using the default constructor, x should be 0, \n";
	cout<<"x's value is: "<<x<<endl<<endl;
	
	cout<<"***C_STR CONSTRUCTOR TEST****\n";
	const char initialNumber[12]="19493829090";
	cout<<"using the C_STR constructor to make y an initial value of 19493829090 \n";
	bigInt y(initialNumber);
	cout<<"\n This is the value of y we get: "<<y<<endl<<endl;
	
	cout<<"***INTEGER CONSTRUCTOR TEST***\n";
	bigInt z(12345);
	cout<<"\n This is z constructed with an int of 12345: "<<z<<endl<<endl;

	cout<<"***DOUBLE CONSTRUCTOR TEST***\n";
	bigInt r(12323.4);
	cout<<"\n This is the r constructed with a double of 12323.4 (should be 12323): "<<r<<endl<<endl;

	cout<<"***COPY CONSTRUCTOR TEST***\n";
	bigInt s(r);
	cout<<"\n Now we are testing the copy constructor with a big int named s initialized to r (i.e. should be 12323): "<<s<<endl<<endl;
	
	cout<<"***OPERATOR EQUALS TEST***\n";
	cout<<"Now I'm declaring p and setting it equal to r (i.e. 12323): ";
	bigInt p;
	p=r;
	cout<<p<<endl<<endl;

	bigInt ac(499);
	bigInt ad(497);

	cout<<"*** OPERATOR == TEST ***\n";
	cout<< "This Should Print Yes if p==r evaluates correctly: \n";
	cout << "r = " << r << " and x = " << x << endl;

	if(p==r)
	{
		cout<<"YES! \n"<<endl<<endl;
	}
	else
	{
		cout<<"NO! \n"<<endl<<endl;
	}

	cout<<"*** OPERATOR != TEST ***\n";
	cout<<"This should print YES if x != r \n"<<endl;
	cout << "r = " << r << " and x = " << x << endl;

	if(x!=r)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}
	
	cout<<"*** OPERATOR < TEST ***\n";
	cout<<"This should print YES if x<r \n";
	cout << "r = " << r << " and x = " << x << endl;

	if(x<r)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}

	cout<<"*** OPERATOR > TEST ***\n";
	cout<<"This should print YES if r>x \n";
	cout << "r = " << r << " and x = " << x << endl;

	if(r>x)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}




	cout << "OPERATOR >= TEST *** \n";
	cout<<"THIS SHOULD PRINT YES IS r >= x \n";
	cout << "R = " << r << " and X = " << x << endl;
 	if(r>=x)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}	

	cout << "OPERATOR <= TEST *** \n";
	cout<<"THIS SHOULD PRINT YES IS r <= x \n";
	cout << "r = " << r << " and x = " << x << endl;
 	if(r<=x)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}		

	cout << "OPERATOR <= TEST *** \n";
	cout<<"THIS SHOULD PRINT YES IS r <= x \n";
	cout << "r = " << r << " and x = " << x << endl;
	if(r<=x)
	{
		cout<<"YES!"<<endl<<endl;
	}
	else
	{
		cout<<"NO!"<<endl<<endl;
	}	

bigInt ba (1234123);
cout << ba << endl;
	
	cout<<"*** OPERATOR + TEST1 ***\n";
	cout<<"\n HERE ARE THE TWO NUMBERS I AM ADDING and setting equal to r: "<<y<<" + "<<z<<endl;
	cout<<"\n our new r should be 19493841435 \n" << endl;
	r=y+z;
	cout<<"Our New r is: "<<r<<endl;


bigInt bb (30000000);
cout << bb << endl;
bigInt bc  (30000000);
cout << bc << endl;
bigInt bd (bb);
cout <<  bd << endl;



	cout<<"*** OPERATOR + TEST2 ***\n";
	const char initialNumber2[13]= "999999999999";
	bigInt t(initialNumber2);
	cout<<"\n Here are the two numbers I'm adding and setting equal to r: "<<y<< "+"<< t<<endl;
	r=y+t;	
	cout<<"\n Our new r should be 1019493829089 \n"; 
	cout<<"Our New r is: "<<r<<endl<<endl;
	
		cout<<"*** OPERATOR + TEST3 ***\n";

	cout<<"\n Here are the two numbers I'm adding and setting equal to r: "<<bb<< "+"<< bc<<endl;
	r=bb+bc;	
	cout<<"\n Our new r should be 50123412 \n"; 
	cout<<"Our New r is: "<<r<<endl<<endl;

	cout<<"*** OPERATOR += TEST ***\n";
	cout<<"\n Now I'm testing operator += by saying r+=y \n";
	cout<<"r is: "<<r<<" and y is: "<<y<<endl;
	cout<<"so Our new value of r should be 1038987658179"<<endl;
	r+=y;
	cout<<"Our new value of r is: "<<r<<endl<<endl;


	// cout<<"*** OPERATOR += TEST2 ***\n";
	// cout<<"\n Now I'm testing operator += by saying bd+=bb \n";
	// cout<<"bd is: "<<bd<<" and bb is: "<<bb<<endl;
	// cout<<"so Our new value of r should be 2468246"<<endl;
	// bd+=bb;
	// cout<<"Our new value of bd is: "<<bd<<endl<<endl;


	cout<<"*** OPERATOR - TEST ***\n";
	cout<<"\n Now I'm testing operator - by saying r=y-z \n";
	cout<<"\n Here are the two numbers I'm subtracting and setting equal to r: "<<y<< "-"<< z<<endl;
	cout<<"so Our new value of r should be 19493816745"<<endl;
	r=y-z;
	cout<<"Our new value of r is: "<<r<<endl<<endl;





	cout<<"*** OPERATOR - TEST2 ***\n";
	cout<<"\n Now I'm testing operator - by saying r=ac-ad \n";
	cout<<"\n Here are the two numbers I'm subtracting and setting equal to r: "<<ac<< "-"<< ad<<endl;
	cout<<"so Our new value of r should be 2"<<endl;
	bigInt aa(r);
	r=ac-ad;
	cout<<"Our new value of r is: "<<r<<endl<<endl;	


	cout<<"*** OPERATOR -= TEST ***\n";
	cout<<"\n Now I'm testing operator -= by saying r-=z \n";
	cout<<"aa is: "<<aa<<" and z is: "<<z<<endl;
	cout<<"so Our new value of a should be 19493804400"<<endl;
	aa-=z;
	cout<<"Our new value of aa is: "<<aa<<endl<<endl;






	return EXIT_SUCCESS;
}