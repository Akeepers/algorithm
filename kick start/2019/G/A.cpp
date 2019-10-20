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
	int n, m, q, tmp;
	cin >> n >> m >> q;
	unordered_set<int> pages;
	vector<int> readers(q, 0);
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		pages.insert(tmp);
	}
	for (int i = 0; i < q; ++i)
	{
		cin >> readers[i];
	}
	vector<int> count(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int cnt = n / i;
		for (int j = i; j <= n; j += i)
		{
			if (pages.count(j))
				cnt--;
		}
		count[i] = cnt;
	}
	ll res = 0;
	for (auto reader : readers)
	{
		res += count[reader];
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
