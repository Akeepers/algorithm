#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory.h>

using namespace std;

typedef long long ll;

const int N = 100000 + 3;

struct SegTree
{
	int tree[2 * N];
	int n;

	// function to build the tree
	void build(vector<int> arr, int _n)
	{
		n = _n;
		// insert leaf nodes in tree
		for (int i = 0; i < n; i++)
			tree[n + i] = arr[i];

		// build the tree by calculating parents
		for (int i = n - 1; i > 0; --i)
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	// function to update a tree node
	void updateTreeNode(int p, int value)
	{
		// set value at position p
		tree[p + n] = value;
		p = p + n;

		// move upward and update parents
		for (int i = p; i > 1; i >>= 1)
			tree[i >> 1] = tree[i] + tree[i ^ 1];
	}

	// function to get sum on interval [l, r)
	int query(int l, int r)
	{
		int res = 0;

		// loop to find the sum in the range
		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				res += tree[l++];

			if (r & 1)
				res += tree[--r];
		}
		return res;
	}

	void clear()
	{
		memset(tree, N * 2, sizeof(int));
	}
};

SegTree seg;

void slove()
{
	int n, s;
	cin >> n >> s;
	vector<int> trinkets(n);
	unordered_map<int, vector<int>> dicts;
	vector<int> tmp(n, 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> trinkets[i];
		if (dicts.count(trinkets[i]) == 0 || dicts[trinkets[i]].size() < s)
			tmp[i] = 1;
		else if (dicts[trinkets[i]].size() == s)
			tmp[i] = -s;
		else
			tmp[i] = 0;
		dicts[trinkets[i]].emplace_back(i);
		// cnt[trinkets[i]]++;
	}

	seg.clear();
	seg.build(tmp, n);
	int res = 0;
	unordered_map<int, int> cnt;
	for (int l = n - 1; l >= 0; --l)
	{
		res = max(res, seg.query(l, n));
		auto cur = trinkets[l];
		++cnt[cur];
		if (cnt[cur]+s >dicts[cur].size())
		{
			auto pos = cnt[cur] +s-1;
			seg.updateTreeNode(dicts[cur][pos], 1);
			seg.updateTreeNode(dicts[cur][pos+1], -s);
		}
		if (cnt[cur]+s ==dicts[cur].size())
		{
			auto pos = cnt[cur] +s-1;
			seg.updateTreeNode(dicts[cur][pos], 1);
		}
		
	}
	cout << res << endl;
}

int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
	}
	return 0;
}
