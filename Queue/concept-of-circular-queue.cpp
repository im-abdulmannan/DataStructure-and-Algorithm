#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int _size)
    {
        arr = new int[_size];
        size = _size;
        front = -1;
        rear = -1;
    }
    /** isFull()
     * @return true if the queue is full
     */
    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    /** isEmpty
     * @return true if the queue is empty,
     */
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    /** Enqueue
     * @return data {to input data into the queue at rear position}
     */
    void Enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = data;
        cout << "Enqueued " << arr[rear] << endl;
    }

    /** Dequeue
     * @return it removes the data at the front from the queue
     */
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        int temp = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        cout << "Dequeueing..." << temp << endl;
    }

    /** peek
     * @return the value at the front of the queue
     */
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    CircularQueue cq(5);
    cq.Enqueue(2);
    cq.Enqueue(3);
    cq.Enqueue(4);
    cq.Enqueue(6);
    cq.Enqueue(9);
    cq.Enqueue(10);
    cq.Enqueue(15);
    cout << cq.peek() << endl;
    cq.Enqueue(10);
    cq.dequeue();
    cq.Enqueue(15);
    cout << cq.peek() << endl;
    return 0;
}