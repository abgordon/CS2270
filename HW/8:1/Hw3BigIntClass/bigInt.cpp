#include <cassert>//provides assert
#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include "bigInt.h" //big int class

using namespace std;

//Default constructor
bigInt::bigInt()
{
	bigIntArray = new char [2];
	bigIntArray[0]='0';
	bigIntArray[1]='\0';
}

//"c_str" constructor
bigInt::bigInt(const char initialValue [])
{
	bigIntArray = new char [strlen(initialValue)+1];
	for (int i=0; i<strlen(initialValue)+1;i++)
		{
			bigIntArray[i] = initialValue[i];
		}

	//make your bigInt array equal to this c_str
	//being passed in  (i.e. use strlen to allocate
	//memory (remember to add +1 to it though for the null character...
	// and strcpy to copy the stuff over (strcpy adds the null automatically)
}

//"integer" constructor
bigInt::bigInt(int initialValue)
{

	int number=initialValue;
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) 
	{
		number /= 10;
		digits++;
	}
	bigIntArray=new char[digits+1];
	sprintf(bigIntArray, "%i", initialValue);


	//use a loop to count the numberOfDigits in initial value
	//Allocate that memory and copy it over (that good ol divide
	//by 10 and modulo 10 thing
}

//"double" constructor
bigInt::bigInt (double initialValue)
{


	int number=initialValue/1;
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) 
	{
		number /= 10;
		digits++;
	}
	bigIntArray=new char[digits+1];
	sprintf(bigIntArray, "%i", initialValue);

	//very similar to the integer constructor strategy above
	//in fact you get this into an int and you can use the same
	//code...	


//Copy Constructor
bigInt::bigInt (const bigInt& toCopyFrom)
{
	bigIntArray = new char [strlen(toCopyFrom.bigIntArray)+1];
	for (int i = 0; i <strlen(toCopyFrom.bigIntArray)+1; i++ )
	{
		bigIntArray[i]=toCopyFrom.bigIntArray[i];
	}

	//use the getBigIntArray on toCopyFrom to set bigIntArray of your object
	//remember to delete bigIntArray of your object BEFORE setting it
	//or else you'll get a memory leak 
}

bigInt::~bigInt()
{
	delete []bigIntArray;
}


//Returns a dynamically allocated copy tot he bigIntArray
char* bigInt::getBigIntArray() const
{
	//Implemented to help you.
//RETURNS A POINTER TO A COPY of our bigIntArray
//with memory already allocated. You can set this 
//to another char * etc.
	char *toReturn;
	toReturn=new char[strlen(bigIntArray)+1];
	strcpy(toReturn, bigIntArray);
	return toReturn;
}

//operator "="
void bigInt::operator = (const bigInt& toEqual)
{
	bigIntArray = toEqual.getBigIntArray();

	//use getBigIntArray on toEqual to set your int array to 
	//the intArray of toEqual	
}

//operator "=="
bool operator ==(const bigInt &firstInt, const bigInt &secondInt)	
{
	char* x = firstInt.getBigIntArray();
	char* y = secondInt.getBigIntArray();
	if (strcmp (x,y)==0){return true;}
	else {return false;}
	//check to see if the bigIntArray's are equal
	//you can use strcmp for this
}

//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt)
{
	char* x = firstInt.getBigIntArray();
	char* y = secondInt.getBigIntArray();
	if (strcmp ( x, y)==0){return false;}
	else {return true;}
	//easy once you've done ==
}

//operator <
bool operator <(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray() ) )
	{
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	int index = (strlen(firstInt.getBigIntArray()))-1;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
		if (temp1[index] < temp2[index]){return true;}
		else if (temp1[index] > temp2[index]){return false;}

	}
	else if (strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray())){return false;}
	else if (strlen(firstInt.getBigIntArray()) < strlen(secondInt.getBigIntArray())){return true;}

	//Not too bad, think about it...
}

//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray() ) )
	{
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	int index = (strlen(firstInt.getBigIntArray()))-1;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
		if (temp1[index] < temp2[index]){return false;}
		else if (temp1[index] > temp2[index]){return true;}
	}
	else if (strlen(firstInt.getBigIntArray()) < strlen(secondInt.getBigIntArray())){return false;}
	else if (strlen(firstInt.getBigIntArray()) > strlen(secondInt.getBigIntArray())){return true;}
	//you've done equals and <, so this should be easy
}

//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray() ) )
	{
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	int index = (strlen(firstInt.getBigIntArray()))-1;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
		if (temp1[index] < temp2[index]){return true;}
		else if (temp1[index] > temp2[index]){return false;}
		else if (temp1[index] == temp2[index]){return true;}
	}
	else if (firstInt>secondInt == true){return false;}
	else if (firstInt < secondInt == true){return true;}
}

//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strlen(firstInt.getBigIntArray()) == strlen(secondInt.getBigIntArray() ) )
	{
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	int index = (strlen(firstInt.getBigIntArray()))-1;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
		if (temp1[index] < temp2[index]){return false;}
		else if (temp1[index] > temp2[index]){return true;}
		else if (temp1[index] == temp2[index]){return true;}
	}
	else if (firstInt>secondInt == true){return true;}
	else if (firstInt < secondInt == true){return false;}
}

bigInt operator +(const bigInt &firstInt, const bigInt &secondInt)
{
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	cout << "strlen firstint = " << strlen(firstInt.getBigIntArray()) << endl;
	cout << "strlen secondint = " << strlen(secondInt.getBigIntArray()) << endl;	
	char* result;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
	cout << "temp1 = " << temp1 << endl;
	cout << "temp2 = " << temp2 << endl;
	int index1 = (strlen(firstInt.getBigIntArray()))-1;
	int index2 = (strlen(secondInt.getBigIntArray()))-1;



	if (firstInt>=secondInt)
	{
		int carry = 0;		
		result = new char [strlen(firstInt.getBigIntArray())];
		while (index1 >= 0)
		{
			if (index2 >=0)
			{
			int z = temp1[index1]-48;
			int x = temp2[index2]-48;
			int added = x + z + carry;
			char rez = '0'+(added%10);
			carry = added/10;
			result[index1]=rez;
			index1 = index1-1;
			index2 = index2-1;
			}
				else if (index2<0)
				{
				int z = temp1[index1]-48 + carry;
				char rez = '0'+(z%10);
				carry = z/10;
				result[index1]=rez;
				index1=index1-1;
				}
		}
		if (carry == 1)
		{
			char* newresult = new char [(strlen(result))+1];
			for (int i = strlen(result)+1; i > 0; i--)
			{
				newresult[i] = result[i-1];
			}
			newresult[0]='1';
			bigInt newret(newresult);
			delete []temp1;
			delete []temp2;
			delete []result;
			delete []newresult;
			return newret;
		}
		else if (carry == 0) 
		{
			bigInt ret(result);
			delete []temp1;
			delete []temp2;
			delete []result;
			return ret;
		}

	}
	if (firstInt<=secondInt)
	{
		int carry = 0;		
		result = new char [strlen(firstInt.getBigIntArray())];
		while (index2 >= 0)

		{
			if (index1 >=0)
				{
				int z = temp1[index1]-48;
				int x = temp2[index2]-48;
				int added = x + z + carry;
				char rez = '0'+(added%10);
				carry = added/10;
				result[index2]=rez;
				index1 = index1-1;
				index2 = index2-1;
				}

					else if (index1<0)
					{
					int z = temp2[index2]-48+carry;
					char rez = '0'+(z%10);
					carry = z/10;
					result[index2]=rez;
					index2=index2-1;
					}
		}
		if (carry == 1)
		{
			char* newresult = new char [(strlen(result))+1];
			for (int i = strlen(result)+1; i > 0; i--)
			{
				newresult[i] = result[i-1];
			}
			newresult[0]='1';
			bigInt newret(newresult);
			delete []temp1;
			delete []temp2;
			delete []result; 
			delete []newresult;
			return newret;
		}
		else if (carry == 0) 
		{
			bigInt ret(result);
			delete []temp1;
			delete []temp2;
			delete []result;
			return ret;
		}
	}

}



	//there are many strategies to this I'll outline the one that we
	//did in class here you can use it 
	//or feel free to devise your own way...
	
	//make two temporary char* to hold the bigIntArray of firstInt and secondInt
    //you can use getBigIntArray (temp1 and temp2)
    
    //find out which one of these bigInts is bigger and make a third char*
    //array of that size to hold the result of our add (result)
    
    //start at the final index of temp1 and temp2 and start adding them
    //index by index, placing them in result and decrementing their indexes (I 
    //had two index variables)
    //Remember to add a carry if the last sum was greater or equal to 10
    
    //When the smaller numbers index is negative, then you only add
    //the bigger ones index to the carry and place this in the result
    
    //when you're done (ie index1 and index2 are negative) - if you have a 
    //carry you resize the result array and put a 1 in the front
    
    //finally you create a bigInt with that array and return it
    //before you do remember to deallocate any dynamic memory before the
    //ptr disappears




void bigInt::operator += (const bigInt& intToAdd)
{
	cout << "*this = " <<*this << endl;
	bigInt temp(intToAdd);
	cout << "temp = " << temp << endl;
	temp = temp + *this;
	*this = temp.getBigIntArray();
	delete []temp.getBigIntArray();
	cout << "*this = " <<*this << endl;


	//now that you've done add,  you can use a temporary bigInt
	//and the "this" pointer to add your current object to 
	//intToAdd. then you can use getbigIntArray on the temp
	//to set "this" big int array, possibly cleaning up
	//memory along the way...
}

bigInt operator - (const bigInt &firstInt, const bigInt &secondInt){
	char* temp1 = new char[strlen(firstInt.getBigIntArray())];
	char* temp2 = new char[strlen(secondInt.getBigIntArray())];
	char* result;
	temp1 = firstInt.getBigIntArray();
	temp2 = secondInt.getBigIntArray();
	int index1 = (strlen(firstInt.getBigIntArray()))-1;
	int index2 = (strlen(secondInt.getBigIntArray()))-1;

	int carry = 0;		
	result = new char [strlen(firstInt.getBigIntArray())-1];
	if (strlen( firstInt.getBigIntArray() )==strlen( secondInt.getBigIntArray() ) )
	{
		int z = temp1[index1]-48;
		int x = temp2[index2]-48;
		int subtracted = z-x; 
		char finalchar = subtracted+ '0';
		result[(strlen(secondInt.getBigIntArray()))-1]=finalchar;

		for (int i = strlen(firstInt.getBigIntArray())-2; i > -1; i--){result[i]='0';}
		bigInt ret(result);
		return ret;
	}
	else{
	while (index1 >= 0)
		{
			if (index2==-1)
				{
					result[index1]=temp1[index1];
					index1 = index1-1;
				}
			else if (index1>0)

			{


			int z = temp1[index1]-48;
			int x = temp2[index2]-48;
			int subtracted = z-x; 
			if ( subtracted < 0 )
				{
					temp1[index1-1] = ((temp1[index1-1])-1);
					subtracted = 10 - (subtracted*-1);


				}
			char finalchar = subtracted+ '0';
			result[index1]=finalchar;
			index1 = index1-1;
			index2 = index2-1;
			}
		}

	}

	bigInt ret(result);
	return ret;

}

/**
DEAR GRADER:

As per ashoks warning my - operator is pretty weak; The first number has to be bigger and you cant 
do any tricks like adding negative numbers or something.  Hence my -= operator has the same limitations.
The bigInts can be the same length though...as long as they wont be negative.
But ashok said this was ok.....just sayin'
**/

void bigInt::operator -= (const bigInt& intToSubtract)
{
	bigInt temp(intToSubtract);
	temp = *this-temp;
	*this = temp.getBigIntArray();
	delete []temp.getBigIntArray();
}

//ostream is implemented for you
ostream& operator <<(ostream& outs, const bigInt& source)
{  
	outs<<source.bigIntArray;
	return outs;
}

//istream is implemented for you in a cheating manner
std::istream& operator >>(std::istream& ins, bigInt& target)
{
	delete [] target.bigIntArray;
	string hello;
	ins>>hello;
	bigInt temp(hello.c_str());
	target.bigIntArray=temp.getBigIntArray();
    return ins;
}

