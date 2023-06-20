#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int explore(const unordered_map<int, vector<int>> &graph, int node, unordered_set<int> &visited)
{
    if (visited.count(node))
        return 0;

    visited.insert(node);
    int size = 1;

    for (int neighbor : graph.at(node))
    {
        size += explore(graph, neighbor, visited);
    }

    return size;
}

int largestComponent(const unordered_map<int, vector<int>> &graph)
{
    unordered_set<int> visited;
    int longest = 0;

    for (const auto &kvp : graph)
    {
        int node = kvp.first;
        int size = explore(graph, node, visited);

        if (size > longest)
        {
            longest = size;
        }
    }

    return longest;
}

int main()
{
    unordered_map<int, vector<int>> graph;

    graph[0] = {8, 1, 5};
    graph[1] = {0};
    graph[5] = {0, 8};
    graph[8] = {0, 5};
    graph[2] = {3, 4};
    graph[3] = {2, 4};
    graph[4] = {3, 2};

    int longestComponent = largestComponent(graph);

    cout << "Longest Component Size: " << longestComponent << endl;
    // Output: Longest Component Size: 4

    return 0;
}