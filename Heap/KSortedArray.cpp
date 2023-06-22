#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

vector<int> sortK(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k + 1);
    vector<int> result(arr.begin(), arr.begin() + k + 1);

    int index = 0;
    for (int i = k + 1; i < arr.size(); i++) {
        result[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty()) {
        result[index++] = pq.top();
        pq.pop();
    }
    
    return result;
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int k = 2;
    vector<int> arr = {2, 6, 3, 12, 56, 8};
    int n = arr.size();

    vector<int> sortedArr = sortK(arr, k);

    cout << "Following is the Sorted Array: " << endl;
    printArray(sortedArr);

    return 0;
}
