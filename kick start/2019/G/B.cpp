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

int seed = 13331;

void slove()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	vector<ll> count(50, 0);
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			count[i] += (nums[j] & 1);
			nums[j] = nums[j] >> 1;
		}
	}
	// ll min = 0, max = 0, t1 = 0, t2 = 0;
	ll res = -1;
	
	for (int i = 49; i >= 0; --i)
	{
		ll cur = 0;
		for (int j = i; j >= 0; --j)
		{
			int a = n - count[j];
			if (a < count[j])
			{
				cur += pow(2, j) * a;
				// min += pow(2, i) * a;
				res += pow(2, j);
				// max += pow(2, i) * count[i];
			}
			else
			{
				cur += pow(2, j) * count[j];
				// min += pow(2, i) * count[i];
				// max += pow(2, i) * a;
			}
			if(cur>m){
				res = -1;
				break;
			}
		}
		if(res!=-1)
			break;
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
