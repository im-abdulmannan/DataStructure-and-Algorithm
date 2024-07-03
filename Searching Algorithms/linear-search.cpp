#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        cout << i << " : " << arr[i] << endl;
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 50, 55, 23, 5, 78, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 90;

    cout << linearSearch(arr, n, x) << endl;

    return 0;
}