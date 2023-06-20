#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool explore(const unordered_map<int, vector<int>> &graph, int current, unordered_set<int> &visited)
{
    if (visited.count(current))
        return false;

    visited.insert(current);

    for (int neighbor : graph.at(current))
    {
        explore(graph, neighbor, visited);
    }

    return true;
}

int connectedComponentsCount(const unordered_map<int, vector<int>> &graph)
{

    unordered_set<int> visited;
    int count = 0;

    for (const auto &kvp : graph)
    {
        int node = kvp.first;
        if (explore(graph, node, visited))
        {
            count++;
        }
    }

    return count;
}


int main() {
     unordered_map<int, vector<int>> graph;
    graph[0] = {8, 1, 5};
    graph[1] = {0};
    graph[5] = {0, 8};
    graph[8] = {0, 5};
    graph[2] = {3, 4};
    graph[3] = {2, 4};
    graph[4] = {3, 2};

    int count = connectedComponentsCount(graph);

    cout << "Connected Components Count: " << count << endl;
    // Output: Connected Components Count: 2

    return 0;
}