#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

void slove()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);
    vector<int> res(n, 0);
    vector<bool> visited(n, true);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        degree[a]++;
        degree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            q.push(i);
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        visited[cur] = false;
        degree[cur]--;
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            auto next = graph[cur][i];
            if (visited[next] && (--degree[next] == 1))
                q.push(next);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (degree[i] != 0)
            q.push(i);
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
            if (!visited[graph[cur][i]])
            {
                res[graph[cur][i]] = res[cur] + 1;
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
    }

    for (int i = 0; i < n; i++)
        cout << " " << res[i];
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ":";
        slove();
    }
    return 0;
}