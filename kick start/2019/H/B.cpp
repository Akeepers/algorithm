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

const vector<int> dx = {1, -1};
const vector<int> dy = {1, -1};

void bfs(stack<pair<int, int>> postions, int cnt, int depth, int n, bitset<MAX> board)
{
	auto cur = postions.top();
	postions.pop();
	while (board[cur.first * n + cur.second] == 1)
	{
		auto cur = postions.top();
		postions.pop();
	}
	bitset<MAX> board1(board);
	while (cur.first < n && cur.second < n)
	{
		int pos = cur.first * n + cur.second;
		board.flip(pos);
		if (board.test(pos))
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		cur.first++;
		cur.second++;
	}
	if (cnt == 0)
		return depth
}

void slove()
{
	int n;
	char tmp;
	cin >> n;

	bitset<MAX> board;
	int cnt = 0;
	stack<pair<int, int>> postions;
	// vector<vector<int>> board(n, vector<int>(n, 1));
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			cin >> tmp;
			if (tmp == '.')
			{
				cnt++;
				board.set(1 * n + j);
				postions.push(make_pair(i, j));
			}
			else
			{
				board.reset(i * n + j);
			}
		}
	}
	int res = INT_MAX;
	for (ll i = 0; i < (1 << 4 * n - 2); ++i)
	{
		bitset<MAX> board1(board);
		int cur = 0;
		for (int k = 0; k < 4 * n - 2; ++k)
		{
			int l = 0, r = 0;
			if (i & (1 << k))
			{
				cur++;
				if (k < n)
				{
					l = k;
					while (l < n && r < n)
					{
						int pos = l * n + r;
						board1.flip(pos);
						l++;
						r++;
					}
				}
				else if (k < 2 * n - 1)
				{
					r = k - n + 1;
					while (l < n && r < n)
					{
						int pos = l * n + r;
						board1.flip(pos);
						l++;
						r++;
					}
				}
				else if (k < 3 * n - 2)
				{
					l = k - 2 * n + 2;
					while (l >= 0 && r >= 0)
					{
						int pos = l * n + r;
						board1.flip(pos);
						l--;
						r--;
					}
				}
				else
				{
					l = n - 1;
					r = k - 3 * n + 2;
					while (l >= 0 && r >= 0)
					{
						int pos = l * n + r;
						board1.flip(pos);
						l--;
						r--;
					}
				}
			}
			if(board1.none()){
				res = min(res, cur);
			}
		}
	}
	cout << res << endl;
}
// int res = 0;
// if (cnt == 0)
// 	cout << res << endl;


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
