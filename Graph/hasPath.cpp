#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class hasPath
{
public:
    bool depthFirst(const unordered_map<char, vector<char>> &graph, char src, char dst)
    {
        if (src == dst)
        {
            return true;
        }

        const vector<char> &neighbors = graph.at(src);
        for (char neighbor : neighbors)
        {
            if (depthFirst(graph, neighbor, dst) == true)
            {
                return true;
            }
        }

        return false;
    }

    bool breadthFirst(const unordered_map<char, vector<char>> &graph, char src, char dst)
    {
        queue<char> que;
        que.push(src);

        while (!que.empty())
        {
            char current = que.front();
            que.pop();

            if (current == dst)
                return true;
            const vector<char> &neighbors = graph.at(current);
            for (char neighbor : neighbors)
            {
                que.push(neighbor);
            }
        }

        return false;
    }
};

int main()
{
    hasPath hp;
    unordered_map<char, vector<char>> graph{
        {'f', {'g', 'i'}},
        {'g', {'h'}},
        {'h', {}},
        {'i', {'g', 'k'}},
        {'j', {'i'}},
        {'k', {}}};

    bool depthFirst = hp.depthFirst(graph, 'f', 'k');
    cout << "Depth First\nPath exists: " << (depthFirst ? "Yes" : "No") << endl;

    bool breadthFirst = hp.breadthFirst(graph, 'f', 'k');
    cout << "\nBreadth First\nPath exists: " << (breadthFirst ? "Yes" : "No") << endl;

    return 0;
}
