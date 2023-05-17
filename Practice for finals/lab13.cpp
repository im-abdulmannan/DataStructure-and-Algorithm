// Linked List Based Implementation of List ADT

#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class List
{
private:
    Node *head;

public:
    List() : head(nullptr) {}

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool search(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display()
    {
        Node *current = head;
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
    List list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display(); // Output: 10 20 30

    list.remove(20);

    list.display(); // Output: 10 30

    std::cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << std::endl; // Output: Search 10: Found
    std::cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl; // Output: Search 20: Not Found

    return 0;
}
