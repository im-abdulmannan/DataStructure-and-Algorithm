#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
   int left = 0, right = size - 1;

   while (left <= right)
   {
      int middle = left + (right - left) / 2;
      cout << "Middle: " << arr[middle] << endl;
      if (arr[middle] == target)
      {
         return middle; // return the middle if it equals to the target
      }
      else if(arr[middle] > target) {
         right = middle - 1; // shift right to the left half of the current array
      } else {
         left = middle + 1; // shift left to the right half of the current array
      }
   }

   return -1; // return -1 if the target is not found in the given array.
}

int main()
{
   int arr[] = {10,
                20,
                30,
                40,
                50,
                60,
                70,
                80};
   int size = sizeof(arr) / sizeof(arr[0]);
   int x = 100;

   cout << binarySearch(arr, size, x) << endl;

   return 0;
}
