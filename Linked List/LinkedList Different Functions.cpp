#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void addFirst(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addLast(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    void addKth(int data, int k)
    {
        if (k < 0 || k > size)
        {
            cout << "\nInvalid position" << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = data;

        if (k == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < k - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "\nThe Linked List is Already Empty." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteKth(int k)
    {
        if (k < 0 || k >= size)
        {
            cout << "\nInvalid position" << endl;
            return;
        }

        if (k == 0)
        {
            deleteFirst();
            return;
        }

        Node *current = head;
        for (int i = 0; i < k - 1; i++)
        {
            current = current->next;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

    void deleteAll()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

        head = NULL;
        size = 0;
    }

    void display()
    {
        Node *current = head;
        while (current != NULL)
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
    int size, data, position, opt = 1;
    cout << "\nEnter the Size of List: ";
    cin >> size;

    while (opt != 0)
    {
        cout << "\nPress 1 to Add Element at Start of List." << endl;
        cout << "Press 2 to Add Element at End of List." << endl;
        cout << "Press 3 to Add Element at K Position of List." << endl;
        cout << "Press 4 to Delete ELement from Start of List." << endl;
        cout << "Press 5 to Delete ELement from Kth Position of List." << endl;
        cout << "Press 6 to Delete All Element." << endl;
        cout << "Press 0 to Exit." << endl;
        cout << "\nEnter Your Choice: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\nEnter the Data: ";
            cin >> data;
            list.addFirst(data);
            cout << endl;
            cout << "\nThe Linked List is: ";
            list.display();
            break;

        case 2:

            cout << "\nEnter the Data: ";
            cin >> data;
            list.addLast(data);
            cout << endl;
            cout << "\nThe Linked List is: ";
            list.display();
            break;

        case 3:
            cout << "\nEnter the Position: ";
            cin >> position;
            cout << "\nEnter the Data: ";
            cin >> data;
            list.addKth(data, position);
            cout << endl;
            cout << "\nThe Linked List is: ";
            list.display();
            break;

        case 4:
            list.deleteFirst();
            cout << "\nThe Linked List is: ";
            list.display();
            break;

        case 5:
            cout << "\nEnter the Position: ";
            cin >> position;
            list.deleteKth(position);
            cout << "\nThe Linked List is: ";
            list.display();
            break;

        case 6:
            list.deleteAll();
            cout << "\nThe Linked List is: ";
            list.display();
            break;
        }
    }

    return 0;
}