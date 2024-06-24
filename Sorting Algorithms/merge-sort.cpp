#include <iostream>
using namespace std;

/** @brief To merge two sorted arrays
 * @param arr[] The array to be merged.
 * @param start The start index of the array
 * @param mid The middle index of the array
 * @param end The end index of the array
 */
void merge(int arr[], int const start, int const mid, int const end)
{
    // Declaring the size of two subArrays
    int const sizeOfsubArrayLeft = mid - start + 1;
    int const sizeOfsubArrayRight = end - mid;

    // Creating two temporary subArrays
    int *leftArray = new int[sizeOfsubArrayLeft];
    int *rightArray = new int[sizeOfsubArrayRight];

    // Copy data to temporary arrays
    for (int i = 0; i < sizeOfsubArrayLeft; i++)
    {
        leftArray[i] = arr[start + i];
    }
    for (int j = 0; j < sizeOfsubArrayRight; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int idxOfLeftSubArray = 0, idxOfRightSubArray = 0;
    int idxOfMergedArray = start;

    // Merging the temp left and right sub arrays
    while (idxOfLeftSubArray < sizeOfsubArrayLeft && idxOfRightSubArray < sizeOfsubArrayRight)
    {
        if (leftArray[idxOfLeftSubArray] <= rightArray[idxOfRightSubArray])
        {
            arr[idxOfMergedArray] = leftArray[idxOfLeftSubArray];
            idxOfLeftSubArray += 1;
        }
        else
        {
            arr[idxOfMergedArray] = rightArray[idxOfRightSubArray];
            idxOfRightSubArray += 1;
        }
        idxOfMergedArray += 1;
    }

    // Copying the data from leftSubArray if there is no rightSubArray
    while (idxOfLeftSubArray < sizeOfsubArrayLeft)
    {
        arr[idxOfMergedArray] = leftArray[idxOfLeftSubArray];
        idxOfLeftSubArray += 1;
        idxOfMergedArray += 1;
    }

    // Copying the data from rightSubArray if there is no leftSubArray
    while (idxOfRightSubArray < sizeOfsubArrayRight)
    {
        arr[idxOfMergedArray] = rightArray[idxOfRightSubArray];
        idxOfRightSubArray += 1;
        idxOfMergedArray += 1;
    }

    // Delete Temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

/** @param arr[] Array to be sorted
 * @param start Start index of the array
 * @param end End index of the array
 * @brief Divide the array into subsequences
 */
void mergeSort(int arr[], int const start, int const end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
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

/** @brief Driver program to test above functions */
int main()
{
    int arr[] = {12, 6, 13, 5, 16, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Display" << endl;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sort Array Display" << endl;
    printArray(arr, arr_size);

    return 0;
}
