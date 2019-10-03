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
	vector<ll> walls(n + 1, 0);
	unordered_set<ll> unique;
	for (int i = 1; i <= n; ++i)
	{
		cin >> walls[i];
		unique.insert(walls[i]);
	}
	vector<ll> nums(unique.begin(), unique.end());
	auto t = nums.size();
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(t, INF64)));
	vector<vector<ll>> minD(n + 1, vector<ll>(k + 1, INF64));
	minD[1][0] = 0;
	for (int i = 0; i < t; ++i)
	{
		if (walls[1] != nums[i])
			dp[1][0][i] = 1;
		else
			dp[1][0][i] = 0;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= min(k, i - 1); ++j)
		{
			for (int m = 0; m < t; ++m)
			{
				dp[i][j][m] = dp[i - 1][j][m];
				if (j > 0)
					dp[i][j][m] = min(dp[i][j][m], minD[i - 1][j - 1]);
				if (walls[i] != nums[m])
					dp[i][j][m]++;
				minD[i][j] = min(minD[i][j], dp[i][j][m]);
			}
		}
	}
	ll res = INF64;
	for (int j = 0; j <= k; ++j)
		for (int m = 0; m < t; ++m)
			res = min(res, dp[n][j][m]);
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
