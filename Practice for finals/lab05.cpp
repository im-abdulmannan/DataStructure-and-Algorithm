// Array-based Implementation of Queue ADT

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int data[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    void enQueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = x;
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
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
        return data[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.display();
    cout << q.frontElement() << endl;

    q.deQueue();

    q.display();
    cout << q.frontElement() << endl;

    return 0;
}