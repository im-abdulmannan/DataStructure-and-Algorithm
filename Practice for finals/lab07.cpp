// Array-based Implementation of Circular Queue

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
            return true;

        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;

        return false;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = item;
        cout << item << " enqueued into the queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        int x = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        cout << x << " dequeued from the queue" << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Elements in Queue are: ";
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < MAX_SIZE; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(110);
    cq.enqueue(120);

    cq.display();

    cq.dequeue();

    cq.enqueue(130);
    cq.enqueue(140);
    cq.enqueue(150);

    cq.display();

    return 0;
}