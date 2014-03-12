// x=10   1045        in this case &10 =1045, ie & is a pass by reference to the memory address
// so x = 10, &x=1045

// in the other case of:
// int* p1 = x;
// p1 = 1045, and *p1 = 10






mug* funmug;
(*funmug).getfillamount();
funmug->getfillamount(); // these are identical, the arrow dereferences stuff


//static vs dynamically allocated
//static = stack
//dynamic = heap
//new ==dynamic memory
//you can only access dynamically allocated variables/objects through a POINTER
//you can use delete keyword to get rid of heap memory


int main()
{

}