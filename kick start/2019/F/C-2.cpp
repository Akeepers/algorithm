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

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

void dfs(int cur, vector<vector<int>> &graph, vector<vector<ll>> &dp, vector<bool> &visited, vector<ll> &values)
{
	visited[cur] = true;
	vector<int> adjs;
	for (auto adj : graph[cur])
	{
		if (!visited[adj])
		{
			dfs(adj, graph, dp, visited, values);
			adjs.emplace_back(adj);
		}
	}
	//叶子节点
	if (adjs.empty())
	{
		dp[cur][0] = 0;
		dp[cur][1] = -INF64;
		dp[cur][2] = values[cur];
	}
	else
	{
		dp[cur][0] = 0;
		dp[cur][2] = values[cur];
		dp[cur][1] = values[cur];
		ll d = -INF64;
		bool flag = false;
		for (auto adj : adjs)
		{
			dp[cur][0] += max(dp[adj][0], dp[adj][1]);
			auto m = max(dp[adj][0], max(dp[adj][2], dp[adj][1]));
			if (m == dp[adj][2])
				flag = true;
			else
				d = max(d, dp[adj][2] - m);
			dp[cur][2] += max(dp[adj][0] + values[adj], max(dp[adj][1], dp[adj][2]));
			dp[cur][1] += m;
		}
		if (!flag)
			dp[cur][1] += d;
	}
}

void slove()
{
	int v;
	cin >> v;
	vector<vector<int>> graph(v);
	vector<ll> values(v);
	for (int i = 0; i < v; ++i)
	{
		cin >> values[i];
	}
	for (int i = 0; i < v - 1; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1 - 1].emplace_back(v2 - 1);
		graph[v2 - 1].emplace_back(v1 - 1);
	}
	vector<bool> visited(v, false);
	vector<vector<ll>> dp(v, vector<ll>(3, 0));
	dfs(0, graph, dp, visited, values);
	auto res = max(dp[0][0], max(dp[0][2], dp[0][1]));
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
