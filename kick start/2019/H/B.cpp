#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
#define MAX 10001

void dfs(vector<vector<int>> &graph, int cur, vector<vector<int>> &board, vector<bool> &visited, int &nocolored, int &colored, bool flag)
{
	flag ? colored++ : nocolored++;
	visited[cur] = true;
	for (auto &next : graph[cur])
	{
		if (!visited[next])
		{
			if (board[cur][next] == 1)
				dfs(graph, next, board, visited, nocolored, colored, !flag);
			else
				dfs(graph, next, board, visited, nocolored, colored, flag);
		}
	}
}

void slove()
{
	int n;
	char tmp;
	cin >> n;

	vector<vector<int>> board(4 * n - 2, vector<int>(4 * n - 2, 0));
	vector<vector<int>> graph(4 * n - 2);
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			cin >> tmp;
			int x = i + j, y = 3 * n - 2 - i + j;
			graph[x].push_back(y);
			graph[y].push_back(x);
			if (tmp == '.')
				board[x][y] = board[y][x] = 1;
		}
	}
	vector<bool> visited(4 * n - 2, false);
	int res = 0;
	for (int i = 0; i < 4 * n - 2; ++i)
	{
		if (!visited[i])
		{
			int nocolored = 0;
			int colored = 0;
			dfs(graph, i, board, visited, nocolored, colored, false);
			res += min(nocolored, colored);
		}
	}

	cout << res << endl;
}

int main()
{
	ll t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
	}
	return 0;
}
