#include <iostream>
using namespace std;

void swap_by_ref(int &a, int &b) //&a means the function gets passed the memory adress of a so we pass in memory adress
{
	//because you cannot change the physical location in memory you have to change the value of the variable
    int temp = a;
	//value of a is now b
    a = b;
	//value of b is now a
    b = temp;
}
void swap_by_ptr(int *a, int *b) //*a means the function gets passed the pointer
{
    int temp = *a;
    *a = *b;
    *b = temp;
	//pointers can be null so you dont have to declare them
}

void swap_by_ptr(int *a, int *b);
void swap_by_ref(int &a, int &b);

int main(){
	int x = 5; //Declaring a value for x
	int y = 2;
	int z = 11;
	int *A;  //Declaring the pointer
	int *B;
	int *C;

	//store memory address of value x in memory address A
	A = &x;
	B = &y;
	C = &z;

	cout << x << ' ' << y << '\n';
    cout << *A <<" is the value of the address A.\n";
    cout << *B <<" is the value of the address B.\n";
	cout << "========================================== \n";
	//Break to make console output easier to see

	swap_by_ref(x,y);
	//Checks to see if the swaps worked
	cout << *A <<" is the value of the address A.\n";
	cout << *B <<" is the value of the address B.\n";

	return 0;
}

