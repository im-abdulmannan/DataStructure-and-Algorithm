#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

using namespace std;

int exploreSize(const vector<vector<char>> &grid, int r, int c, unordered_set<string> &visited)
{
    int numRows = grid.size();
    int numCols = grid[0].size();

    if ((r < 0 || r >= numRows) || (c < 0 || c >= numCols))
        return 0;

    if (grid[r][c] == 'W')
        return 0;

    string pos = to_string(r) + "," + to_string(c);
    if (visited.count(pos))
        return 0;

    visited.insert(pos);

    int size = 1;
    size += exploreSize(grid, r - 1, c, visited);
    size += exploreSize(grid, r + 1, c, visited);
    size += exploreSize(grid, r, c - 1, visited);
    size += exploreSize(grid, r, c + 1, visited);

    return size;
}

int minimumIsland(const vector<vector<char>> &grid)
{
    unordered_set<string> visited;
    int numRows = grid.size();
    int numCols = grid[0].size();

    int minSize = numeric_limits<int>::max();

    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            int size = exploreSize(grid, r, c, visited);
            if (size > 0 && size < minSize)
            {
                minSize = size;
            }
        }
    }

    return minSize;
}

int main()
{
    vector<vector<char>> grid = {
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'L', 'W'},
        {'W', 'W', 'L', 'L', 'W'},
        {'L', 'L', 'W', 'L', 'L'}};

    cout << "Island Count: " << minimumIsland(grid);
    // Possible Output: 2 (minimun island)

    return 0;
}