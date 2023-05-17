// Array-based Implementation of Drifting Queue

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class DriftingQueue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    DriftingQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == MAX_SIZE - 1) || front == rear + 1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == MAX_SIZE - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX_SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    int frontElement()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    DriftingQueue dq;

    dq.enqueue(10);
    dq.enqueue(20);
    dq.enqueue(30);
    dq.enqueue(40);

    dq.display();
    cout << dq.frontElement() << endl;

    dq.dequeue();
    dq.display();
    cout << dq.frontElement() << endl;

    return 0;
}