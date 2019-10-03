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

ll cal(vector<vector<int>> &graph, vector<int> &sub, vector<int> &values)
{
	ll res = 0;
	unordered_set<int> visited;
	for (auto item : sub)
	{
		if (!visited.count(item))
		{
			res += values[item];
			visited.insert(item);
		}
		for (auto adj : graph[item])
		{
			if (!visited.count(adj))
			{
				res += values[adj];
				visited.insert(adj);
			}
		}
	}
	return res;
}
void slove()
{
	int v;
	cin >> v;
	vector<vector<int>> graph(v);
	vector<int> values(v);
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
	ll res = -INF64;

	for (ll i = 0; i <= (1 << v); ++i)
	{
		vector<int> sub;
		for (ll j = 0; j < v; ++j)
		{
			if (i & (1 << j))
				sub.emplace_back(j);
		}
		res = max(res, cal(graph, sub, values));
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
