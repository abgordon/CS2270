#ifndef MAIN_GORDON_LINE_H
#define MAIN_GORDON_LINE_H
#include "point.h"
	class line
	{
		public:	
		//constructors
			line(); //default on x axis
			line(const point &a, const point &b); //2 points
			line(const point &a); //from (0,0) and 1 point
			line(const line &source);//copy constructor




	//slope function
			double slope() const;

	//translation function
			void translate(double x_amount, double y_amount);

	//reflection function
			void reflect_x();
			void reflect_y();

	//y-intercept
			double y_intercept() ;


	//op. overload
		void operator = (const line& source);

	//for cin
		friend std::istream& operator >>(std::istream& ins, line& target);
    
	//for cout
   		friend std::ostream& operator <<(std::ostream& outs, const line& source);

   //		friend double y_intercept(line &a) ;



	//getters
			double get_x1() const;
			double get_y1() const;
			double get_x2() const;
			double get_y2() const;

	private:
			double x1;
			double y1;
			double x2;
			double y2;
			double yint;
	};

	bool operator == (const line &line1, const line &line2); //for our overloaded operator

#endif