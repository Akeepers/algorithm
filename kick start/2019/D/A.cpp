#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

int bitCount(unsigned int n)
{
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

int calMax(vector<int> &nums)
{
	int res = 0, left = 0, right = 0, maxSum = 0, curSum = 0, cur = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		cur ^= nums[i];
		curSum = bitCount(cur);
		if (curSum > maxSum)
		{
			maxSum = curSum;
		}
	}
}
int slove(vector<int> &inputs, vector<pair<int, int>> &modifications)
{
}

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int n, q, tmp1, tmp2;
		cin >> n >> q;
		vector<int> inputs(n);
		vector<pair<int, int>> modifications;
		for (int j = 0; j < n; j++)
			cin >> inputs[j];
		for (int j = 0; j < q; j++)
		{
			cin >> tmp1 >> tmp2;
			modifications[j] = make_pair(tmp1, tmp2);
		}
		auto res = count(str, vecs);
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
