#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, 1, -1, 0};

class Solution
{

    bool check(int i, int j, int m, int n) { return (i < m && i >= 0) && (j < n && j >= 0); }

    void dfs(vector<vector<int>> &grid, int x, int y, int cnt, int &res)
    {
        int m = grid.size(), n = grid[0].size();
        if (grid[x][y] == 2 && cnt == 0)
        {
            res++;
            return;
        }
        if (grid[x][y] == -1 || grid[x][y] == 2)
            return;
        cnt--;
        auto tmp = grid[x][y];
        grid[x][y] = -1;
        for (int i = 0; i < 4; ++i)
        {
            auto x1 = x + dx[i], y1 = y + dy[i];
            if (check(x1, y1, m, n))
                dfs(grid, x1, y1, cnt, res);
        }
        grid[x][y] = tmp;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int res = 0, cnt = 1;
        pair<int, int> start;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    start = make_pair(i, j);
                }
                else if (grid[i][j] == 0)
                    cnt++;
            }
        }
        dfs(grid, start.first, start.second, cnt, res);
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}