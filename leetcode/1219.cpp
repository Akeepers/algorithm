#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, 1, -1, 0};

class Solution
{
    bool check(int i, int j, int m, int n)
    {
        return (i < m && i >= 0) && (j < n && j >= 0);
    }

    int dfs(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        auto tmp = grid[x][y];
        grid[x][y] = 0;
        auto res = 0;
        for (int i = 0; i < 4; ++i)
        {

            auto x1 = x + dx[i], y1 = y + dy[i];
            if (check(x1, y1, m, n) && grid[x1][y1] != 0)
            {
                res = max(res, grid[x1][y1] + dfs(grid, x1, y1, m, n));
            }
        }
        grid[x][y] = tmp;
        return res;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                    res = max(res, grid[i][j] + dfs(grid, i, j, m, n));
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