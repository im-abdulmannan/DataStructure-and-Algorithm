#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    Stack(int _size)
    {
        arr = new int[_size];
        top = -1;
        size = _size;
    }

    /** push
     * @param data to input data into the stack at top position
     */
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else if (isEmpty())
        {
            top = 0;
        }
        else
        {
            top += 1;
        }

        arr[top] = data;
        cout << data << " pushed into the stack" << endl;
    }

    /** pop
     * @return it returns the data which is being removed from the stack
     */
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        int temp = arr[top];
        if (top == 0)
        {
            top = -1;
        }
        else
        {
            top -= 1;
        }
        cout << temp << " removed from the stack" << endl;
    }

    /** peek
     * @return the value at the top of the stack
     */
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    /** isEmpty
     * @return true if the stack is empty,
     */
    bool isEmpty()
    {
        return top == -1;
    }

    /** isFull()
     * @return true if the stack is full
     */
    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s(5);
    s.pop();
    s.push(3);
    s.push(4);
    cout << s.peek() << endl;
    s.push(1);
    s.pop();
    s.push(3);
    s.push(4);
    s.push(5);

    return 0;
}
