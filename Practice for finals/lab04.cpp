#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class List
{
private:
    int data[MAX_SIZE];
    int size;

public:
    List()
    {
        size = 0;
    }

    void add(int item)
    {
        if (size < MAX_SIZE)
        {
            data[size] = item;
            size++;
        }
        else
        {
            cout << "List is Full!" << endl;
        }
    }

    void remove(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
        else
        {
            cout << "Invalid Index!" << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

void testList()
{
    List myList;
    myList.add(10);
    myList.add(20);
    myList.add(30);
    myList.add(40);

    cout << "List Elements: ";
    myList.print();

    myList.remove(2);
    cout << "List Elements after Removing Element at Index 2: ";
    myList.print();
}

int main()
{
    testList();

    return 0;
}