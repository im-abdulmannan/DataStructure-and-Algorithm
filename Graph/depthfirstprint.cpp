#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void depthFirstPrint(const unordered_map<char, vector<char>> &graph, char source)
{
    stack<char> stk;
    stk.push(source);

    while (!stk.empty())
    {
        char current = stk.top();
        stk.pop();
        cout << current;

        const vector<char> &neighbors = graph.at(current);
        for (char neighbor : neighbors)
        {
            stk.push(neighbor);
        }
    }
}

int main()
{
    unordered_map<char, vector<char>> graph{
        {'a', {'b', 'c'}},
        {'b', {'d'}},
        {'c', {'f'}},
        {'d', {}},
        {'f', {}}};

    depthFirstPrint(graph, 'a'); // acfbd

    return 0;
}
