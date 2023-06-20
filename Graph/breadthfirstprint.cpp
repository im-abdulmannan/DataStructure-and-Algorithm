#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void breadthFirstPrint(const unordered_map<char, vector<char>> &graph, char source)
{
    queue<char> que;
    que.push(source);

    while (!que.empty())
    {
        char current = que.front();
        que.pop();
        cout << current;

        const vector<char> &neighbors = graph.at(current);
        for (char neighbor : neighbors)
        {
            que.push(neighbor);
        }
    }
}

int main()
{
    unordered_map<char, vector<char>> graph{
        {'a', {'c', 'b'}},
        {'b', {'d'}},
        {'c', {'e'}},
        {'d', {'f'}},
        {'e', {}},
        {'f', {}}};

    breadthFirstPrint(graph, 'a'); // acbedf

    return 0;
}
