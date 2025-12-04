#include <iostream>
using namespace std;

void swap_by_ptr(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_three_pointers(int *a, int *b, int *c)
{
    if (*a > *b) {
        swap_by_ptr(a, b);
    }
    if (*b > *c) {
        swap_by_ptr(b, c);
    }
    if (*a > *b) {
        swap_by_ptr(a, b);
    }
}

int main(){
	int x;
	int y;
	int z;
	int *A;
	int *B;
	int *C;

	A = &x;
	B = &y;
	C = &z;

	cout << "Enter three integers, separated by spaces: ";
	cin >> x >> y >> z;

	cout << "========================================== \n";
	cout << "Before sorting:\n";
	cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
	cout << A << "is the adress of X \n";
	cout << B << "is the adress of Y \n";
	cout << C << "is the adress of Z \n";
	cout << "========================================== \n";

	sort_three_pointers(A, B, C);

	cout << "After sorting:\n";
	cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
	cout << A << "is the adress of X \n";
	cout << B << "is the adress of Y \n";
	cout << C << "is the adress of Z \n";
	cout << "========================================== \n";

	return 0;
}

