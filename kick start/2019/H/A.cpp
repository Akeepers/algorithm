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

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

void slove()
{
	int n, tmp;
	cin >> n;
	vector<int> minHeap;
	vector<int> papers(n, 0);
	cin >> tmp;
	minHeap.emplace_back(tmp);
	make_heap(minHeap.begin(), minHeap.end(), greater<int>());
	int cur = 1;
	for (int i = 2; i <= n; ++i)
	{
		cin >> tmp;
		if (tmp > cur)
		{
			minHeap.push_back(tmp);
			push_heap(minHeap.begin(), minHeap.end(), greater<int>());
		}
		while (!minHeap.empty() && minHeap.front() <= cur)
		{
			pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
			minHeap.pop_back();
		}
		cur = max(cur, (int)minHeap.size());
		// cin >> papers[i];
	}
	cout << cur << endl;
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
