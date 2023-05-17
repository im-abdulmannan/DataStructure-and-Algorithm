#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

int main()
{
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }

    for (int i = 0; i < SIZE + 1; i++)
    {
        if (i < SIZE)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
        else
        {
            cout << "Attempting to access arr[" << i << "]" << endl;
            if (&arr[i] < &arr[0] || &arr[i] >= &arr[SIZE])
            {
                cout << "Array index Out of Bounds!" << endl;
            }
        }
    }

    return 0;
}