


CLASS TEMPLATE IMPLEMENTATION

#ifndef...

template <class Item>
Item maximal (item a, item b)
{
 if (a == b){cout << "those items are the same"}	-you must overload your == operator or << operator to make sure you include for any items or classes you can work with!
}

stacks - LIFO
Queues - FIFO
"Bags" - aka classes 
} should all work with any type of data!  This is why we use templates

template <class Item>
class bag
{
	ITEM is now used in here
	ie:
	public:

	bool erase_one (const Item& target)
	...

	private:
	Item* data; - a dynamic array of "item"        
	-you can make bags of double, ints, bigints, etc (still can't mix doe)
}


#include "bag4.template"   --we don't want people to see or change anything in our templates so we put all implementations
in another file, aka "not inlined," so we avoid that by including everything into the bag4 template
#endif

in implementation file:

template <class Item>
bool bag<Item>::erase_one(const Item& Target)


QUEUE TEMPLATE IMPLEMENTATION

template defining in Main

queue<char> cq;
queue<int> iq;
queue<double> dq;

peep at C++ standard template library
www.cplusplus.com/reference/queue /stack
std::queue
std::stack
stack a;
a.pop etc









