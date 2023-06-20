#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<char, vector<char>> buildGraph(const vector<vector<char>> &edges)
{
    unordered_map<char, vector<char>> graph;

    for (const auto &edge : edges)
    {
        char a = edge[0];
        char b = edge[1];

        if (graph.find(a) == graph.end())
            graph[a] = vector<char>();

        if (graph.find(b) == graph.end())
            graph[b] = vector<char>();

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}
int shortestPath(const vector<vector<char>> &edges, char nodeA, char nodeB)
{
    unordered_map<char, vector<char>> graph = buildGraph(edges);
    unordered_set<char> visited;
    queue<pair<char, int>> q;
    q.push(make_pair(nodeA, 0));
    visited.insert(nodeA);

    while (!q.empty())
    {
        pair<char, int> current = q.front();
        q.pop();

        char node = current.first;
        int distance = current.second;

        if (node == nodeB)
            return distance;

        for (char neighbor : graph[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(make_pair(neighbor, distance + 1));
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<char>> edges = {
        {'w', 'x'},
        {'x', 'y'},
        {'z', 'y'},
        {'z', 'v'},
        {'w', 'v'}};

    char nodeA = 'w';
    char nodeB = 'z';

    int distance = shortestPath(edges, nodeA, nodeB);

    cout << "Shortest distance between " << nodeA << " and " << nodeB << ": " << distance << endl;
    // Possible output: 2 (distance between nodeA and nodeB)

    return 0;
}
