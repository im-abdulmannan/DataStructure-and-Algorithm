// Array-based Implementation of Stack ADT

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        if (top == MAX_SIZE - 1)
            return true;

        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;

        return false;
    }

    void push(int item)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = item;

        cout << item << " pushed to stack" << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        int item = arr[top];
        top--;
        cout << item << " popped from stack" << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Elements in Stack are:: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    st.display();

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.display();

    st.push(70);
    st.push(80);
    st.push(90);

    st.pop();

    st.display();

    return 0;
}