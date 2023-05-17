#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1; // Returning a default value
        }

        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node *current = front;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Output: 10 20 30

    queue.dequeue();

    queue.display(); // Output: 20 30

    std::cout << "Front element: " << queue.getFront() << std::endl; // Output: Front element: 20

    return 0;
}
