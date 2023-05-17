#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class TwoWayStack
{
private:
    int arr[MAX_SIZE];
    int top1, top2;

public:
    TwoWayStack()
    {
        top1 = -1;
        top2 = MAX_SIZE;
    }

    bool isFull1()
    {
        if (top1 + 1 == top2)
            return true;

        return false;
    }

    bool isFull2()
    {
        if (top2 - 1 == top1)
            return true;

        return false;
    }

    bool isEmpty1()
    {
        if (top1 == -1)
            return true;
        return false;
    }

    bool isEmpty2()
    {
        if (top2 == MAX_SIZE)
            return true;
        return false;
    }

    void push1(int item)
    {
        if (isFull1())
        {
            cout << "Stack 1 Overflow!" << endl;
            return;
        }
        top1++;
        arr[top1] = item;

        cout << item << " pushed to Stack 1" << endl;
    }

    void push2(int item)
    {
        if (isFull2())
        {
            cout << "Stack 2 is Overflow!" << endl;
            return;
        }
        top2--;
        arr[top2] = item;

        cout << item << " pushed to Stack 2" << endl;
    }

    void pop1()
    {
        if (isEmpty1())
        {
            cout << "Stack 1 Underflow!" << endl;
            return;
        }
        int item = arr[top1];
        top1--;
        cout << item << " popped from Stack 1" << endl;
    }

    void pop2()
    {
        if (isEmpty2())
        {
            cout << "Stack 2 Underflow!" << endl;
            return;
        }
        int item = arr[top2];
        top2++;
        cout << item << " popped from Stack 2" << endl;
    }

    void display1()
    {
        if (isEmpty1())
        {
            cout << "Stack 1 is Empty" << endl;
            return;
        }
        cout << "Elements in Stack 1 are: ";
        for (int i = top1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void display2()
    {
        if (isEmpty2())
        {
            cout << "Stack 2 is Empty" << endl;
            return;
        }
        cout << "Elements in Stack 2 are: ";
        for (int i = top2; i < MAX_SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    TwoWayStack tws;

    tws.push1(10);
    tws.push1(20);
    tws.push2(30);
    tws.push2(40);
    tws.push1(50);
    tws.push2(60);

    tws.display1();
    tws.display2();

    tws.pop1();
    tws.pop2();
    tws.pop2();
    tws.pop1();

    tws.display1();
    tws.display2();

    tws.push1(70);
    tws.push2(80);
    tws.push2(90);

    tws.pop2();

    tws.display1();
    tws.display2();

    return 0;
}