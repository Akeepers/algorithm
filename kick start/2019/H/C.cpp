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

void slove()
{
	bool res = false;
	vector<ll> nums(200, 0);
	ll cnt = 0, tmp, cnt1 = 0, cnt2 = 0, sum = 0;
	vector<pair<ll, int>> others;
	for (int i = 1; i <= 9; ++i)
	{
		cin >> tmp;
		if (tmp > 10)
		{
			cnt1++;
			others.push_back(make_pair(tmp, i));
		}
		else
		{
			sum += tmp;
			while ((tmp--) > 0)
			{
				nums[cnt++] = i;
			}
		}
		if (tmp > 6)
			cnt2++;
	}
	if (cnt1 >= 2 || cnt2 >= 3)
	{
		cout << "Yes" << endl;
		return;
	}
	if (!others.empty())
	{
		tmp = sum + ((others[0].first - sum) & 1);
		while ((tmp--) > 0)
			{
				nums[cnt++] = others[0].second;
			}
	}

	do
	{
		ll cur = 0;
		int t = 1;
		for (int i = 0; i < cnt; ++i)
		{
			cur += t * nums[i];
			t = -t;
		}
		if (cur % 11 == 0)
		{
			res = true;
			break;
		}
	} while (next_permutation(nums.begin(), nums.begin() + cnt));
	cout << (res ? "YES" : "NO") << endl;
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
