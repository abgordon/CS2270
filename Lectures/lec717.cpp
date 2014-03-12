//Destructors

//Format:  ~Mug()
// goes in mug.cpp and mug.h like your other class functions

//you never explicitly call the destructor (not entirely true but usually)

//deep copies:

// someClass one
// char *ptr
// someClass::someCLass(someClass toCopy)
// {
// ptr = new char[90000];
// for (int i=0; i<90000;i++){ptr[i] = toCopy.ptr[i]}
// }

//Each element is copied one by one
//default copy constructor does a shallow copy.  
//a deep copy is where you go and COPY THE DATA POINTERS ARE POINTING TO and point your pointers to that data

//Recursion: function calling itself

