#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
};

int count(struct Node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
};

void Insert(struct Node *p, int index, int value)
{
    struct Node *t;
    if (index < 0 || index > count(p))
        return;

    t = new Node;
    t->data = value;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    cout << "Display Linked List before Insertion: ";
    Display(first);
    int index = 2, value = 34;
    Insert(first, index, value);
    cout << "\n\nDisplay Linked List after Insertion: ";
    Display(first);

    return 0;
}