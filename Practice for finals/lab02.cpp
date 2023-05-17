// Implementing Pointers in C++

#include <iostream>
using namespace std;

int main()
{
    int num = 42;
    int *ptr = &num;

    cout << "The Value of the Number is: " << num << endl;
    cout << "The Address of the Number is: " << &num << endl;
    cout << "The Value of the Pointer is: " << ptr << endl;
    cout << "The Value at the Address pointed to by a pointer is: " << *ptr << endl;

    *ptr = 100;

    cout << "The New Value of Number is: " << num << endl;

    return 0;
}