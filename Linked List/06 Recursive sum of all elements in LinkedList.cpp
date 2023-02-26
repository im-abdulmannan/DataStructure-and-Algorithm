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

int RSum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return RSum(p->next) + p->data;
    }
};

int main(void)
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    cout << RSum(first);

    return 0;
}