#include <iostream>
using namespace std;
int main()
{

}

// HEADER STRUCTURE:

//#ifndef MUG_H  -- the MACROGAURD, stops the header from being included twice
//#define MUG_H -- including the header twice stops the compilation

// --> header BS

//#endif -- ?


//Public : Can be accessed from outside the class code - "Interface with the outside world"
//Ideally people should be able to use your class by only employing Public functions

//"Getters and setters" - 

//Private vars/functions: can only be accessed by: The object itself, other objects of the same type, or Friend functions

//friend functions - not member functions - written OUTSIDE of class, in header file
//friend functions can access private vars

//copy constructor:  mug::mug(const mug& source)
//constructor with default arguments: mug(double initialfill=23.2)
//sets vars of two objects and sets them equal to each other

//const functions, ie double get_y() const { return y; }
//"const" ensures that this function will not change the object in any way
//"GETTERS" are often const


//overloading: Making two of the same function with two implementations

//"Operator overloading:" using boolean/binary operators on objects - ie, using modulo on two objects?
//arithmetic operators in c++ are binary operators

//Namespace STD: A group of variables/functions that go together
//STD is the standard one, but you can make your own with your own functions