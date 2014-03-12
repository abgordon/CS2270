#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cassert>
#include "line.h"
#include "point.h"



using namespace std;


	point::point(double initial_x, double initial_y) //included definition of points becuase I didn't include point.cpp
	{
		x=initial_x;
		y=initial_y;
	}
	double point::get_x() const { return x; }
	double point::get_y() const { return y; }

		line::line() //default on x-axis
		{
			x1=-1.0;
			x2=1.0;
			y1=0.0;
			y2=0.0;
			yint=(y1-((y2-y1)/(x2-x1))*x1);
		}

		line::line(const point &a, const point &b)
		{
			x1=a.get_x();
			y1=a.get_y();
			x2=b.get_x();
			y2=b.get_y();
		}
		line::line(const point &a)
		{
			x1=0.0;
			y1=0.0;
			x2=a.get_x();
			y2=a.get_y();
		}
		line::line(const line &source)
		{
			x1=source.get_x1();
			x2=source.get_x2();
			y1=source.get_y1();
			y2=source.get_y2();

		}



	double line::slope() const
	{
		if (x1==x2)
		{
			cout << "slope equals infinity!";
			return 0.0;
		}else 
		{
			double slope = (y2-y1)/(x2-x1);
			return slope;
		}
	}
	void line::translate(double x_amount, double y_amount)
	{
		x1 += x_amount;
		x2 += x_amount;
		y1 += y_amount;
		y2 += y_amount;
	}

	void line::reflect_x()
	{
		y1 = -y1;
		y2 = -y2;
		x1 = x1;
		x2 = x2;
	}
	void line::reflect_y()
	{
		x1 = -x1;
		x2 = -x2;
		y1 = y1;
		y2 = y2;
	}

	double line::get_x1() const {return x1;}
	double line::get_y1() const {return y1;}
	double line::get_x2() const {return x2;}
	double line::get_y2() const {return y2;}

	void line::operator = (const line& source) 
	{
		x1=source.x1;
		y1=source.y1;
		x2=source.x2;
		y2=source.y2;
	}
	double line::y_intercept() 
	{
		double slope = (y2-y1)/(x2-x1);
		double yint=(y1-(slope*x1));
		return yint;
	}
	// double y_intercept(line &a)
	// {
	// 	 double yint=((a.get_y1())-(a.slope()*a.get_x1()));
	// 	return yint;
	// }

	// bool operator == (const line &line1, const line &line2)
	// {
	// 	if ( line1.slope()==line2.slope()
	// 		and 
	// 		 line1.y_intercept()==line2.y_intercept())
	// 		 {return true;}
	// 	// if (line1.get_x1() == line2.get_x1() and line1.get_x2() == line2.get_x2() and line1.get_y1()==line2.get_y1() and line1.get_y2()==line2.get_y2() ) {return true;}
	// 	else {return false;}
	// }

	istream& operator >>(istream& ins, line& target)
	{
		ins >> target.x1;
		ins >> target.y1;
		ins >> target.x2;
		ins >> target.y2;
		return ins;
	}
	ostream&operator <<(ostream& outs, const line& source)
	{
		outs << source.x1;
		outs << source.y1;
		outs << source.x2;
		outs << source.y2;
		return outs;
	}


//GRADER: IGNORE ALL THIS STUFF, this was just random outputs I used to test my stuff before I used test2.cxx


int main()
{
	point p1(3.2, 5.6);
	point p2(4.3,6.7);
	point p3(8.7,23.0);
	line l1(p1, p2);
	line l2(p3);
	line l3(l2);
	line l5;


	cout << "l1 is a line that passes through " << l1.get_x1() << ", " << l1.get_y1() << " and " <<l1.get_x2()<<", " << l1.get_y2()<<endl;
	cout << "l2 is a line that passes through " << l2.get_x1() << ", " << l2.get_y1() << " and " <<l2.get_x2()<<", " << l2.get_y2()<<endl;
	cout << "l3 is a line that passes through " << l3.get_x1() << ", " << l3.get_y1() << " and " <<l3.get_x2()<<", " << l3.get_y2()<<endl;
	cout << "l5 is a line that passes through " << l5.get_x1() << ", " << l5.get_y1() << " and " <<l5.get_x2()<<", " << l5.get_y2()<<endl;
	cout << "point 1 has an x value of " << p1.get_x() << " and a y value of " << p1.get_y() << endl;

	cout << "line l1 has a slope of " << l1.slope()<<endl;

	cout<<"Now we will translate l1 by (5, 6.3) \n";
    l1.translate(5, 6.3);
    cout << "l1 is a line that passes through " << l1.get_x1() << ", " << l1.get_y1() << " and " <<l1.get_x2()<<", " << l1.get_y2()<<endl;
	cout<<"Now we will reflect l2 over the x axis and l3 over the y axis \n";
    l2.reflect_x( );
    l3.reflect_y( );
	cout << "l2 is a line that passes through " << l2.get_x1() << ", " << l2.get_y1() << " and " <<l2.get_x2()<<", " << l2.get_y2()<<endl;
	cout << "l3 is a line that passes through " << l3.get_x1() << ", " << l3.get_y1() << " and " <<l3.get_x2()<<", " << l3.get_y2()<<endl;
	
	cout<<"Now we will pass l1 into our copy constructor to make l4 \n";
    line l4(l1);
	cout << "l4 is a line that passes through " << l4.get_x1() << ", " << l4.get_y1() << " and " <<l4.get_x2()<<", " << l4.get_y2()<<endl;

    if (l1 == l4) cout << "l1 and l4 are equal" << endl;
    else cout << "l1 and l4 are not equal" << endl;
    if (l2 == l4) cout << "l2 and l4 are equal" << endl;
    else cout << "l2 and l4 are not equal" << endl;
	
	cout<<"Now we will use the overloaded = operator to set l1 to l3 \n";
    l1 = l3;

    if (l1 == l3) cout << "l1 and l3 are equal" << endl;
    else cout << "l1 and l3 are not equal" << endl;
    if (l2 == l3) cout << "l2 and l3 are equal" << endl;
    else cout << "l2 and l3 are not equal" << endl;
    line l6(p1,p2);
    // cout <<"The y-intercept of l6 is at " << y_intercept(l6)<< endl;




   	// cout<< "please type in 4 values to define the two points of l3 \n";
    // cin >> l3;
    // cout << "l3 = " << l3 << endl;


}













