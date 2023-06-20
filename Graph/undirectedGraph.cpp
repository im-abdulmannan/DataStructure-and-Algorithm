#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

bool hasPath(const unordered_map<char, vector<char>> &graph, char src, char dst, unordered_set<char> &visited)
{
    if (src == dst)
        return true;

    if (visited.count(src))
        return false;

    visited.insert(src);

    for (char neighbor : graph.at(src))
    {
        if (hasPath(graph, neighbor, dst, visited))
        {
            return true;
        }
    }

    return false;
}

unordered_map<char, vector<char>> buildGraph(const vector<pair<char, char>> &edges)
{
    unordered_map<char, vector<char>> graph;

    for (const auto &edge : edges)
    {
        char a = edge.first;
        char b = edge.second;

        if (graph.find(a) == graph.end())
            graph[a] = {};

        if (graph.find(b) == graph.end())
            graph[b] = {};

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

bool undirectedGraph(const vector<pair<char, char>> &edges, char nodeA, char nodeB)
{
    unordered_map<char, vector<char>> graph = buildGraph(edges);
    unordered_set<char> visited;

    return hasPath(graph, nodeA, nodeB, visited);
}

int main()
{
    vector<pair<char, char>> edges = {
        {'i', 'j'},
        {'k', 'i'},
        {'m', 'k'},
        {'m', 'l'},
        {'o', 'n'}};

    cout << undirectedGraph(edges, 'j', 'm') << endl;
    // Possible output: 1 (indicating true)

    cout << undirectedGraph(edges, 'm', 'n') << endl;
    // Possible output: 0 (indicating false)

    return 0;
}
