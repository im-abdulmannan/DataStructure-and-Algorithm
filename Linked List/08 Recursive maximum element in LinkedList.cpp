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

int RecursiveMinimum(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MAX;
    }

    x = RecursiveMinimum(p->next);

    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

int main(void)
{
    int A[] = {2, 78, 3, 67, 4};
    create(A, 5);
    cout << RecursiveMinimum(first);

    return 0;
}