#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

typedef struct
{
	int cur;
	vector<int> adv;
} Node;

void dfs(int cur, const vector<vector<int>> &graph, vector<bool> &visited, int &cnt)
{
	visited[cur] = true;
	if (graph[cur].empty())
	{
		cnt++;
		return;
	}
	for (auto next : graph[cur])
	{
		if (visited[next])
			continue;
		dfs(next, graph, visited, cnt);
		cnt++;
	}

}

int slove(int n, vector<vector<int>> &graph)
{
	int cnt = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
			dfs(i, graph, visited, cnt);
	}
	return 2 * (cnt - 1) + n - cnt;
}
int main()
{

	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{

		int n, m;
		cin >> n >> m;
		vector<vector<int>> graph(n);
		for (int j = 0; j < m; j++)
		{
			int x1, x2;
			cin >> x1 >> x2;
			graph[x1 - 1].emplace_back(x2 - 1);
			graph[x2 - 1].emplace_back(x1 - 1);
		}
		auto res = slove(n, graph);
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
