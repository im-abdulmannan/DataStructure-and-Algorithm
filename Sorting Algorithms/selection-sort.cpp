#include <iostream>
#include <vector>
using namespace std;

/** @param arr[] Array to be sorted
 * @param n The size of the array
 */
void selectionSort(int arr[], int n)
{
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the remaining unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

/** @brief Display data in array
 * @param arr[] Array to display
 * @param size Size of the array
 */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 3, 2, 1, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
