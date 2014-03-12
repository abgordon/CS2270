#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cassert>
#include "point.h"


using namespace std;


	point::point(double initial_x, double initial_y) //constructor
	{
		x=initial_x;
		y=initial_y;
	}

	void point::translate(double x_amount, double y_amount)
	{
		x += x_amount;
		y += y_amount;
	}

	void point::scale(double m)
	{
		x = x*m;
		y = y*m;
	}

	void point::reflect_x()
	{
		y = -y;
		x=x;
	}
	void point::reflect_y()
	{
		x = -x;
		y=y;
	}

	void point::rotate(double r)
	{
		x = (x*cos(r)-y*sin(r));
		y = (x*sin(r)+y*cos(r));
	}
	double point::get_x() const { return x; }
	double point::get_y() const { return y; }

	void point::set_x(double new_x)
	{
		x = new_x;
	}
	void point::set_y(double new_y)
	{
		y=new_y;
	}

	void point::operator = (const point& source) 
	{
		x=source.x;
		y=source.y;
	}

	istream& operator >>(istream& ins, point& target)
	{
		ins >> target.x;
		ins >> target.y;
		return ins;
	}
	ostream&operator <<(ostream& outs, const point& source)
	{
		outs << source.x;
		outs << source.y;
		return outs;
	}

	bool operator == (const point &point1, const point &point2)
	{
		if (point1.get_x() == point2.get_x() and point1.get_y() == point2.get_y()) {return true;}
		else {return false;}
	}

//GRADER: IGNORE ALL THIS STUFF, this was just random outputs I used to test my stuff before I used test1.cxx

int main()
{
	point p1(20,30);
	point p2(20,30);
	cout << "point 1 has an x value of " << p1.get_x() << " and a y value of " << p1.get_y() << endl;
	p1.scale(1.61803);
	cout << "when scaled by 1.61803 p1 has a x value of " << p1.get_x() << " and a y value of " << p1.get_y() << endl;
	p1.reflect_x();
	p1.reflect_y();
	cout <<"With x and y reflected the values of x and y are " << p1.get_x() << " and " << p1.get_y() << endl;
	p1.rotate(1);
	cout << "and then rotated clockwise by 1 radian (57.295 degrees), x and y = " << p1.get_x() << " and " << p1.get_y() << endl;
	cout << "\n" << endl;
	point p3(p1);
	cout << "Now we have copied point 1, creating point 3.  P3 has x,y vals of " << p3.get_x() << " and " << p3.get_y() << endl;
    if (p1 == p3) cout << "p1 and p3 are equal" << endl;
    else cout << "p1 and p3 are not equal" << endl;
    if (p2 == p3) cout << "p2 and p3 are equal" << endl;
    else cout << "p2 and p3 are not equal" << endl;

	cout<<"Now we redefine p3 by using the assignment operator with p2 \n";
    p3 = p2;

    if (p1 == p3) cout << "p1 and p3 are equal" << endl;
    else cout << "p1 and p3 are not equal" << endl;
    if (p2 == p3) cout << "p2 and p3 are equal" << endl;
    else cout << "p2 and p3 are not equal" << endl;

    cout<< "Please type 2 values to define p3 \n";
    cin >> p3;
    cout << "p3 = " << p3 << endl;



}
