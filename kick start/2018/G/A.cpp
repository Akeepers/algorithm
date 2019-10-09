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
	int n, k;
	cin >> n >> k;
	vector<int> walls(n + 1, 0);
	int j = 1;
	unordered_map<int, int> indexs;
	for (int i = 1; i <= n; ++i)
	{
		cin >> walls[j];
		if (walls[j] != walls[j - 1])
		{
			j++;
		}
	}
	int cnt = 0;
	walls[0] = walls[1];
	for (int i = 1; i <= n; ++i)
	{
		cnt += walls[i] != walls[i - 1];
	}
	if (cnt <= k)
	{
		cout << 0 << endl;
		return;
	}
	if (cnt == k + 1)
	{
		cout << 1 << endl;
		return;
	}
	vector<pair<int, int>> items;
	// auto res = cnt - k;
	// auto pos = 1;
	for (int i = 1; i <= cnt; ++i)
	{
		if (!indexs.count(walls[i]))
		{
			indexs[walls[i]] = i;
		}
		else if (indexs[walls[i]] == i - 1)
		{
			indexs[walls[i]] = i;
		}
		else
		{
			items.emplace_back(make_pair(i,indexs[i]);
			indexs[i]=i;
		}
	}
	if (items.empty())
	{
		cout << cnt - k << endl;
		return;
	}
	sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return (a.second - a.first) < (b.second - b.first); });
	for (auto item : items)
	{
		auto d = item.second - item.first - 1;
		cnt -= d + 1;
		if (cnt > k)
			continue;
		if (cnt == k)
		{
			cout << d << endl;
			return;
		}
		cout << cnt - k - 1 << endl;
		return;
	}
	cout << cnt - k << endl;
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
