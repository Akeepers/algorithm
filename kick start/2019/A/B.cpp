#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

typedef long long ll;

const vector<int> dx = {-1, 0, 0, 1};
const vector<int> dy = {0, 1, -1, 0};

inline bool isOutOfBound(int x, int y, int r, int c)
{
    return x < 0 || x >= r || y < 0 || y >= c;
}

bool check(int cur, int r, int c, vector<vector<int>> &dist)
{
    int x = -INF;
    int y = INF;
    int z = -INF;
    int w = INF;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (dist[i][j] > cur)
            {
                x = max(x, i + j);
                y = min(y, i + j);
                z = max(z, i - j);
                w = min(w, i - j);
            }
    if (w == INF)
        return true;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (abs(x - (i + j)) <= cur &&
                abs(y - (i + j)) <= cur &&
                abs(z - (i - j)) <= cur &&
                abs(w - (i - j)) <= cur)
                return true;
    return false;
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
        q.pop();
        maxDist = dist[cur.first][cur.second];
        for (int i = 0; i < 4; ++i)
        {
            auto x = cur.first + dx[i];
            auto y = cur.second + dy[i];
            if (!isOutOfBound(x, y, r, c) && dist[x][y] == INT_MAX)
            {
                dist[x][y] = maxDist + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    int high = maxDist, low = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid, r, c, dist))
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << high + 1 << endl;
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
