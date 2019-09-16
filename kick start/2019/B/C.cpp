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

using namespace std;

typedef long long ll;

const int N = 100000 + 3;

struct SegTree
{
	int tree[2 * N];

	// function to build the tree
	void build(vector<int> arr)
	{
		int n = arr.size();
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
};

SegTree seg;

void slove()
{
	ll n, s;
	cin >> n >> s;
	vector<ll> inputs;
	unordered_map<ll, vector<ll>> dicts;

	for (ll i = 0; i < n; ++i)
	{
		cin >> inputs[i];
		dicts[inputs[i]].emplace_back(i);
	}

	seg.clear();
	ll res = 0;
	for (int l = n - 1; l >= 0; ++l)
	{
		seg.update(1, l, n);
	}
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
