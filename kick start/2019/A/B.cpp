#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, 1, -1, 0};

inline bool isOutOfBound(int x, int y, int r, int c)
{
    return x < 0 || x >= r || y < 0 || y >= c;
}
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
    queue<pair<int, int>> q;
    for (int i = 0; i < r; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < c; ++j)
        {
            if (tmp[j] == '1')
            {
                q.push(make_pair(i, j));
                grid[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }

    //multi-bfs
    int maxDist = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        maxDist = dist[cur.first][cur.second];
        for (int i = 0; i < 4; ++i)
        {
            auto x = cur.first + dx[i];
            auto y = cur.second + dy[i];
            if (!isOutOfBound(x, y, r, c) && dist[x][y] != INT_MAX)
            {
                dist[x][y] = maxDist + 1;
                q.push(make_pair(x, y));
            }
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
