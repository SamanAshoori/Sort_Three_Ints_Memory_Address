//memory.cpp
#include "memory.hpp"

void demo_stack_heap(){
	int stack_value = 42;
	int* heap_value = new int(42);
	std::cout << "Stack value is: " << stack_value << " Heap value is: " << heap_value << '\n';
	delete heap_value;
}
