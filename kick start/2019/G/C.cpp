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

ll res;
vector<ll> pow3(21, 1);

void dfs(ll v1, ll v2, int cur, vector<pair<ll, ll>> &nums, vector<ll> &sumA, vector<ll> &sumB, int h, int n)
{
	if (v1 >= h && v2 >= h)
	{
		res += pow3[n - cur];
		return;
	}
	if (cur >= n)
		return;
	if (v1 + sumA[n - cur] < h || v2 + sumB[n - cur] < h)
		return;
	dfs(v1 + nums[cur].first, v2, cur + 1, nums, sumA, sumB, h, n);
	dfs(v1, v2 + nums[cur].second, cur + 1, nums, sumA, sumB, h, n);
	dfs(v1 + nums[cur].first, v2 + nums[cur].second, cur + 1, nums, sumA, sumB, h, n);
}

void slove()
{
	int n, h;
	cin >> n >> h;
	vector<pair<ll, ll>> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i].first;
	for (int i = 0; i < n; ++i)
		cin >> nums[i].second;
	sort(nums.begin(), nums.end(), greater<pair<ll, ll>>());
	vector<ll> sumA(n + 1, 0), sumB(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		sumA[n - i] = sumA[n - i - 1] + nums[i].first;
		sumB[n - i] = sumB[n - i - 1] + nums[i].second;
		res = 0;
	}
	res = 0;
	dfs(0, 0, 0, nums, sumA, sumB, h, n);
	cout << res << endl;
}

int main()
{
	int t = 0;
	cin >> t;
	pow3[0] = 1;
	for (int i = 1; i <= 20; ++i)
		pow3[i] = pow3[i - 1] * 3;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
	}
	return 0;
}
