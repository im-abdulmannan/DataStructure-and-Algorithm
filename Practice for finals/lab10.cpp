// Searching a value in a List

#include <iostream>
using namespace std;

int main()
{
    int n, value, pos;

    cout << "Enter Number of Elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " Elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Value to Search: ";
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            pos = i;
            break;
        }
    }

    if (pos == 0)
    {

        cout << value << " not Found in the List" << endl;
    }
    else
    {
        cout << value << " Found at Position " << pos + 1 << "." << endl;
    }

    return 0;
}