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

// void dfs(vector<vector<int>> &graph, int cur, vector<int> &res, vector<bool> &visited)
// {
// 	res.emplace_back(cur);
// 	visited[cur] = true;
// 	for (auto item : graph[cur])
// 	{
// 		if (!visited[item])
// 			dfs(graph, item, res, visited);
// 	}
// }

// ll MaxSubSum(vector<int> &vec)
// {
// 	ll maxSum = -INF64;
// 	ll cur = 0;
// 	for (int i = 0; i < vec.size(); ++i)
// 	{
// 		cur += arr[i];
// 	}
// }

void visited(vector<int>)

void slove()
{
	int v;
	cin >> v;
	vector<vector<int>> graph(v);
	vector<int> beaties(v);
	for (int i = 0; i < v; ++i){
		cin >> beaties[i];
	}
	for (int i = 0; i < v - 1; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].emplace_back(v2);
		graph[v2].emplace_back(v1);
	}
	ll res = -INF64;
	

	// vector<int> leafs;
	// for (int i = 0; i < v; ++i)
	// {
	// 	if (graph[i].size() == 1)
	// 		leafs.emplace_back(i);
	// }
	// vector<bool> visited(v, false);
	// vector<vector<int>> res;
	// for (int i = 0; i < v; ++i)
	// {
	// 	if (!visited[i])
	// 	{
	// 		vector<int> tmp;
	// 		dfs(graph, i, tmp, visited);
	// 		res.emplace_back(vector<int>(tmp));
	// 	}
	// }
	// for
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
