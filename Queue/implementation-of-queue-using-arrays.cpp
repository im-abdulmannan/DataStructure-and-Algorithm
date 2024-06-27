#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int _size)
    {
        arr = new int[_size];
        front = -1;
        rear = -1;
        size = _size;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return rear == size - 1;
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

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(10);
    q.enqueue(1);
    cout << q.peek() << endl;
    q.enqueue(9);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.peek();

    while (!q.isEmpty())
    {
        cout << q.peek() << endl;
        q.dequeue();
    }

    q.peek();

    q.dequeue();

    return 0;
}