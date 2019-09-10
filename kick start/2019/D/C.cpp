#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;


ll solve(ll n,ll k,vector<ll>& positions,vector<ll>& costs)
{
	ll res = 0;
	
}

int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{

		ll k, n;
		cin >> k >> n;
		vector<ll> positions(n), costs(n);
		for (ll j = 0; j < n; ++j)
		{
			cin >> positions[j];
		}
		for (ll j = 0; j < n; ++j)
		{
			cin >> costs[j];
		}
		auto res = solve(n,k, positions, costs);
		cout << "Case #" << i << ":";
		cout << endl;
	}
	return 0;
}
