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
};

struct Node *RecursiveSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key == p->data)
        return p;

    return RecursiveSearch(p->next, key);
}

int main(void)
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    temp = RecursiveSearch(first, 10);
    cout << temp->data;

    return 0;
}