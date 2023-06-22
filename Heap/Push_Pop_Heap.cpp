#include <iostream>
#include <vector>
using namespace std;

#define SIZE 1001

int heap[SIZE];
int heapSize;

void heapPush(int i)
{
    if (heapSize >= SIZE)
    {
        cout << "Heap OverFlow";
        return;
    }

    heap[heapSize] = i;
    int curr = heapSize;

    while (curr > 0 && heap[(curr - 1) / 2] < heap[curr])
    {
        swap(heap[(curr - 1) / 2], heap[curr]);

        curr = (curr - 1) / 2;
    }
    heapSize += 1;
}

int heapPop()
{
    if (heapSize <= 0)
    {
        cout << "Heap Underflow";
        return 0;
    }

    int curr = 0;
    int popped = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize -= 1;

    while ((2 * curr + 1) < heapSize)
    {
        int child;
        if ((2 * curr + 2) == heapSize)
        {
            child = 2 * curr + 1;
        }
        else
        {
            if (heap[2 * curr + 1] > heap[2 * curr + 2])
                child = 2 * curr + 1;

            else
                child = 2 * curr + 2;
        }

        if (heap[curr] < heap[child])
        {
            swap(heap[curr], heap[child]);

            curr = child;
        }
        else
            break;
    }

    return popped;
}

void showHeap()
{
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void intit()
{
    heapSize = 0;
}

int main()
{
    intit();
    while (1)
    {
        cout << "1. Push\n2. Pop\n3. Show Heap\n4. Terminate\nEnter Option::";
        int opt;
        int element;
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter Element: ";
            cin >> element;
            heapPush(element);
            break;

        case 2:
            cout << "Elements Poped: " << heapPop() << endl;
            break;

        case 3:
            showHeap();
            break;

        default:
            return 0;
        }
    }
}