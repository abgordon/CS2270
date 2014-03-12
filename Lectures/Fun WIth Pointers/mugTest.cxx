//The mug class Demo
//Program that tests how the mug class works

#include <iostream>  //provides cout and cin
#include <cstdlib> //provides the all important EXIT_SUCCESS
#include "mug.h"   //provides our mug class

using namespace std; //allows standard library items to be used

int main()
{
	mug *firstMug; //Uses default constructor, should be empty. Note no empty
				  //empty parenthesis on the default constructor! this will error!

	mug myFunMug;
	
	firstMug=&myFunMug;
	cout<<"This is the address of my fun mug "<<&myFunMug<<endl;
	cout<<"This is the address of first mug pointer "<<firstMug<<endl;
	cout<<"This is the value of my fun mug "<<myFunMug<<endl;
	cout<<"This is the value of the address first mug pointer is pointing to "<<*firstMug<<endl;   //????
	
	cout<<"This is the REAL value of the address first mug pointer is pointing to "<<(*firstMug).getFillAmount()<<endl;
	
	cout<<"I can also call member functions on pointers to objects by using the -> operator on the non asterixed pointer: "<<firstMug->getFillAmount()<<endl;
	
	
	return EXIT_SUCCESS;
}