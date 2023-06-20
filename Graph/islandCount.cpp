#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool explore(const vector<vector<char>> &grid, int r, int c, unordered_set<string> &visited)
{
  int numRows = grid.size();
  int numCols = grid[0].size();

  if ((r < 0 || r >= numRows) || (c < 0 || c >= numCols))
    return false;

  if (grid[r][c] == 'W')
    return false;

  string pos = to_string(r) + "," + to_string(c);
  if (visited.count(pos))
    return false;

  visited.insert(pos);

  explore(grid, r - 1, c, visited);
  explore(grid, r + 1, c, visited);
  explore(grid, r, c - 1, visited);
  explore(grid, r, c + 1, visited);

  return true;
}

int islandCount(const vector<vector<char>> &grid)
{
  unordered_set<string> visited;
  int count = 0;
  int numRows = grid.size();
  int numCols = grid[0].size();

  for (int r = 0; r < numRows; r++)
  {
    for (int c = 0; c < numCols; c++)
    {
      if (explore(grid, r, c, visited))
      {
        count++;
      }
    }
  }

  return count;
}

int main()
{
  vector<vector<char>> grid = {
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'W', 'W', 'L', 'W'},
      {'W', 'W', 'L', 'L', 'W'},
      {'L', 'W', 'W', 'L', 'L'}};

  cout << "Island Count: " << islandCount(grid);
  // Possible Output: 3 (island count)

  return 0;
}