#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void bfs(int a, int b, int r, int c, int d, int &res, vector<vector<int>> &dist)
{
    if (d >= dist[a][b])
        return;
    dist[a][b] = d;
    res = max(res, d);
    if (a + 1 < r)
        bfs(a + 1, b, r, c, d + 1, res, dist);
    if (b + 1 < c)
        bfs(a, b + 1, r, c, d + 1, res, dist);
    if (a - 1 >= 0)
        bfs(a - 1, b, r, c, d + 1, res, dist);
    if (b - 1 >= 0)
        bfs(a, b - 1, r, c, d + 1, res, dist);
}

void slove()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    string tmp;
    int res = -1;
    for (int i = 0; i < r; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < c; ++j)
        {
            if (tmp[j] == '1')
            {
                grid[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (grid[i][j] == 0)
                continue;
            bfs(i, j, r, c, 0, res, dist);
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (grid[i][j] == 1)
                continue;
            auto t(dist);
            bfs(i, j, r, c, 0, res, t);
        }
    }
    cout << res << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        slove();
    }
    return 0;
}
