#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
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
        if (head == nullptr)
            return;

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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display(); // Output: 10 20 30

    list.remove(20);

    list.display(); // Output: 10 30

    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}