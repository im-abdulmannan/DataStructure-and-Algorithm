#include<iostream>
using namespace std;

int main() {
    int A[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter a Number: ";
        cin >> A[i];
    }

    cout << "\nThe Numbers in Array are = ";
    for (int j = 0;j < 5; j++) {
        cout << A[j] << " ";
    }

    return 0;
}