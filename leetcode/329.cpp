#include <iostream>
#include <vector>

using namespace std;

const vector<int> dx = {1, 0, 0, -1};
const vector<int> dy = {0, 1, -1, 0};

class Solution
{
    bool check(int m, int n, int i, int j)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dist, int x, int y, int last)
    {
        if (!check(matrix.size(), matrix[0].size(), x, y))
            return 0;
        if (matrix[x][y] <= last)
            return 0;
        if (dist[x][y] != 0)
            return dist[x][y];
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            dist[x][y] = max(dist[x][y], dfs(matrix, dist, x1, y1, matrix[x][y]) + 1);
        }
        return dist[x][y];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cur = dfs(matrix, dist, i, j, INT_MIN);
                res = max(res, cur);
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