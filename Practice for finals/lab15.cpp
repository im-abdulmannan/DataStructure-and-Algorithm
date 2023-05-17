#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int getTop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Returning a default value
        }

        return top->data;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        Node *current = top;
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
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Output: 30 20 10

    stack.pop();

    stack.display(); // Output: 20 10

    std::cout << "Top element: " << stack.getTop() << std::endl; // Output: Top element: 20

    return 0;
}
