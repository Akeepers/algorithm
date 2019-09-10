#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

typedef struct
{
	ll x, c;
} Node;

ll solve(ll n, ll k, vector<Node> &positions)
{
	ll k1 = k / 2;
	ll k2 = k - k1;
	priority_queue<ll> q1;
	priority_queue<p, vector<p>, greater<>> q2;
	unordered_set<ll> indexs;

	ll left = 0;
	for (int i = 0; i < k1; ++i)
	{
		auto v = positions[i].c - positions[i].x;
		left += v;
		q1.push(v);
	}
	for (int i = k1 + 1; i < n; ++i)
	{
		q2.push(make_pair(positions[i].c + positions[i].x, i));
	}
	ll right = 0;

	for (int i = 0; i < k2; ++i)
	{
		auto top = q2.top();
		right += top.first;
		indexs.insert(top.second);
		q2.pop();
	}
	ll res = left + right + k1 * positions[k1].x - k2 * positions[k1].x + positions[k1].c;
	for (int i = k1 + 1; i < n - k2; ++i)
	{
		auto cur = positions[i];
		if (!q1.empty())
		{
			auto tmp = cur.c - cur.x;
			if (tmp < q1.top())
			{
				left = left - q1.top() + tmp;
				q1.pop();
				q1.push(tmp);
			}
		}
		if (!indexs.empty())
		{
			if (indexs.count(i))
			{
				int t;
				do
				{
					t = q2.top().second;
					q2.pop();
				} while (t <= i && !q2.empty());
				if (q2.empty())
					break;
				indexs.erase(i);
				indexs.insert(t);
				right = right - positions[i].c - positions[i].x + positions[t].c + positions[t].x;
			}
		}
		res = min(res, left + right + k1 * cur.x - k2 * cur.x + cur.c);
	}
	return res;
}

int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{

		ll k, n;
		cin >> k >> n;
		vector<Node> positions(n);
		for (ll j = 0; j < n; ++j)
		{
			cin >> positions[j].x;
		}
		for (ll j = 0; j < n; ++j)
		{
			cin >> positions[j].c;
		}
		sort(positions.begin(), positions.end(), [](const Node &a, const Node &b) { return a.x < b.x; });
		auto res = solve(n, k, positions);
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
