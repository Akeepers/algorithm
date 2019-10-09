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
const ll INF = 1e17;

void slove()
{
	ll n, o, d, a, b, c, m, l;
	cin >> n >> o >> d;
	vector<ll> candies(n + 1, 0);
	cin >> candies[1] >> candies[2] >> a >> b >> c >> m >> l;

	vector<ll> sum(n + 1, 0);
	for (ll i = 3; i <= n; ++i)
		candies[i] = (a * candies[i - 1] + b * candies[i - 2] + c) % m;
	for (ll i = 1; i <= n; ++i)
	{
		candies[i] += l;
		sum[i] = sum[i - 1] + candies[i];
	}
	multiset<ll> mt;

	ll r = 1,odd = 0,res = -INF;
	for (ll i = 1; i <= n; ++i)
	{
		while (r <= n && odd + (candies[r] & 1) <= o)
		{
			mt.insert(sum[r]);
			odd += (candies[r++] & 1);
		}
		if (r <= i)
		{
			r = i + 1;
		}
		else
		{
			auto it = mt.lower_bound(sum[i - 1] + d + 1);
			if (it != mt.begin())
			{
				--it;
				res = max(res, *it - sum[i - 1]);
			}
			mt.erase(mt.find(sum[i]));
			odd -= (candies[i] & 1);
		}
	}
	if (res == -INF)
		cout << "IMPOSSIBLE" << endl;
	else
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
