#include <bits/stdc++.h>
using namespace std;

/** @brief A Bubble Sort
 * @param arr[] Array to be sorted
 * @param n Size of array
 */
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/** @brief Display data in array
 * @param arr[] Array to display
 * @param size Size of the array
 */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Display array: \n";
    printArray(arr, N);
    bubbleSort(arr, N);
    cout << "Display sorted array: \n";
    printArray(arr, N);
    return 0;
}
