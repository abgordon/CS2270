//resizing dynamic arrays

int main()
{
	int* ptr = new ptr[400]; //you have a 400 element array
	//how to resize: you can make a new 500 element array, copy the list, and delete the old one
	int* new_ptr = new new_ptr[500];
	for(int i=0; i <500; i++){new_ptr[i]=ptr[i];}
	delete ptr;

	//but this is memory-innefecient  - ideally we wouldn't want to resize all the time

	class bag
	{
	public:
		typedef int value_type;   //typedef = creating your own type - every time you say value_type, it is going to be an int
		typedef std::size_t size_type; //size_t = never negative - size, length, etc
		static const size_type DEFAULT_CAPACITY=30;

		//constructors and destructors
		bag(size_type initial_capacity=DEFAULT_CAPACITY);
		bag(const bag& source);

		~bag; // ~ = destructor
		//bag destructor: deleting arrays is like so:   delete[] data;  one line destructor!
		// this is called implicitly WHEN: the mug is about to drop out of scope
		//can be explicitly called, but this is not normally done

		void reserve(size_type new_capacity);
		//"reseving" here refers to resizing the array - making a bag with a bigger capacity
		value_type* fundata = new value_type[new_capacity]


	private:
		value_type *data;
		size_type used;
		size_type capacity;



	};
	//LINKED LISTS
	//"Non coniguous ordered array"
	//each node has data and a pointer to the next node
	//kind of nice because we don't have to deal with arrays; no notion of 'size' here
	//Linked list is NOT A DATA STRUCTURE - linked lists consists of nodes 'node class'

	//made up of nodes in a class or struct, each with data and a pointer
	//last pointer ("tail pointer") = NULL
	//head ptr - points to the first node or NULL, contains no data
	//if head ptr = null we have a linked list with no elements

	//2 getters for the node
	const node* link() const;
	node* link();

	//Linked list toolkit: a set of functions that helps you manipulate a linked list
	//uses nodes but not part of the node class
}














