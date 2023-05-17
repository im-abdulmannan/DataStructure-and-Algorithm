// Searching and Replacing a value in a List

#include <iostream>
using namespace std;

int main()
{
    int n, searchValue, replaceValue;

    cout << "Enter the Number of Elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " Elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value to Search: ";
    cin >> searchValue;

    cout << "Enter the value to Replace: ";
    cin >> replaceValue;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchValue)
        {
            arr[i] = replaceValue;
            found = true;
        }
    }

    if (found)
    {
        cout << searchValue << " was found and replaced by " << replaceValue << endl;
    }
    else
    {
        cout << searchValue << " was not found in the List" << endl;
    }

    cout << "The New List is:: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}