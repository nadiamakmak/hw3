#include <iostream>
#include "stack.h"

int main(){
	Stack<int> test = Stack<int>();

	std::cout << "Empty: " << test.empty() << std::endl;

	test.push(1);
	test.push(4);

	std::cout << "Top: " << test.top() << std::endl;
	test.pop();
	std::cout << "Top after popping: " << test.top() << std::endl;
	test.pop();
	test.pop();

	return 0;
}