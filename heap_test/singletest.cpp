#include <iostream>
#include "../heap.h"
using namespace std;

int main(){
	Heap<int> heap(2);
	heap.push(9);
	heap.push(9);
	heap.push(20);

	cout << heap.top() << endl;
	//EXPECT_EQ(9, heap.top());

	heap.pop();
	heap.pop();

	cout << heap.top() << endl;
	//EXPECT_EQ(20, heap.top());
}