#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const vector<int> dx = {0, 1, -1, 0};
const vector<int> dy = {1, 0, 0, -1};

class Solution
{
    bool check(int m, int n, int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<int>> &grid, int x, int y, int &res)
    {
        res++;
        grid[x][y] = 0;
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (check(grid.size(), grid[0].size(), x1, y1) && grid[x1][y1] == 1)
                dfs(grid, x1, y1, res);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int cur = 0;
                    dfs(grid, i, j, cur);
                    res = max(cur, res);
                }
            }
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}