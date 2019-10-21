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
	ll n, m;
	cin >> n >> m;
	vector<ll> nums(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	vector<ll> count(51, 0);
	for (ll i = 0; i < 51; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			if ((nums[j] & (1ll << i)) > 0)
				count[i]++;
		}
	}
	ll res = 0;
	ll sum = 0;
	for (ll i = 50; i >= 0; --i)
	{
		ll a = n - count[i];
		if (a <= count[i])
		{
			sum += (1ll << i) * a;
			res += (1ll << i);
		}
		else
		{
			sum += (1ll << i) * count[i];
		}
	}
	if (sum > m)
	{
		cout << -1 << endl;
		return;
	}
	for (ll i = 50; i >= 0; --i)
	{
		ll a = n - count[i];
		if (a > count[i])
		{
			if (sum + (a - count[i]) * (1ll << i) <= m)
			{
				sum += (a - count[i]) * (1ll << i);
				res += (1ll << i);
			}
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
