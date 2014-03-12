#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	queue<char> firstqueue, secondqueue;
	stack<char> firststack, secondstack;

	firststack.push('h');
	firststack.push('e');
	firststack.push('r');
	firststack.push('r');
	firststack.push('o');
	firststack.push('p');
	firststack.push('r');
	firststack.push('e');
	firststack.push('a');
	firststack.push('s');
	firststack.push('e');

	cout<<"for string 'herro prease': is it FIFO?" << endl;
	cout << " pushing starting with h...." << endl;
	for (int a = 1; a < 12; a++ )
	{
		secondstack.push(firststack.top());
		firststack.pop();
	}
	cout << endl;
	for (int c = 1; c<12; c++)
	{
		cout<<secondstack.top();
		secondstack.pop();
	}
	cout << endl;



	// firstqueue.push('h');
	// firstqueue.push('e');
	// firstqueue.push('r');
	// firstqueue.push('r');
	// firstqueue.push('o');
	// firstqueue.push('p');
	// firstqueue.push('r');
	// firstqueue.push('e');
	// firstqueue.push('a');
	// firstqueue.push('s');
	// firstqueue.push('e');


	// for (int a = 1; a < 12; a++ )
	// {
	// 	cout << firststack.top() << endl;
	// 	firststack.pop();
	// }

	// for (int i = 1; i < 12; i++ )
	// {
	// 	cout << firstqueue.front() << endl;
	// 	firstqueue.pop();
	// }



}