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
	vector<bool> visited(v, false);
	vector<vector<int>> dp(v, vector<int>(3, -INF64));

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
