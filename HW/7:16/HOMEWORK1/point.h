#ifndef MAIN_GORDON_POINT_H
#define MAIN_GORDON_POINT_H
	class point 
	{
		public:
			point(double initial_x = 0.0, double initial_y = 0.0); //constructor


			//MEMBER FUNCTIONS:


			void translate(double X, double Y);

			void scale(double m); 

			void set_x(double new_x);
			void set_y(double new_y);

			void reflect_x();
			void reflect_y();

			void rotate(double r);

			void operator = (const point& source);


			//Constant member functions:
			double get_x() const;
			double get_y() const;

			//for cin
			friend std::istream& operator >>(std::istream& ins, point& target);
    
  			//for cout
   			friend std::ostream& operator <<(std::ostream& outs, const point& source);



		private:
			double x;
			double y;
	};

	bool operator == (const point &point1, const point &point2); //for our overloaded operator


#endif