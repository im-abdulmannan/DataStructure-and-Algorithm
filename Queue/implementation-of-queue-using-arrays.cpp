#include <iostream>
using namespace std;

class Solution
{
private:
    int arr[10];
    int front = -1, rear = -1;

public:
    bool isEmpty()
    {
        if (front == -1 || rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int n)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = n;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int temp = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Dequeueing " << temp << " from queue." << endl;
        return temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            return arr[front];
        }
        else
        {
            return arr[front + 1];
        }
    }
};

int main()
{
    Solution s;
    s.enqueue(1);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(9);
    s.enqueue(2);
    s.enqueue(5);
    s.enqueue(5);
    s.enqueue(5);
    s.enqueue(5);
    s.enqueue(5);

    s.dequeue();
    s.peek();

    while (!s.isEmpty())
    {
        cout << s.peek() << endl;
        s.dequeue();
    }

    s.peek();

    s.dequeue();

    return 0;
}