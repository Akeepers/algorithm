#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> solve(int n, int m, int g, vector<pair<int, int>> &clockwiseGuest, vector<pair<int, int>> &antiGuest)
{
	vector<pair<int, vector<int>>> consulates(n);
	int pos;
	for (auto guest : clockwiseGuest)
	{
		pos = (guest.second + m) % n;
		consulates[pos].first = m;
		consulates[pos].emplace_back(item.first);
	}
}

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ":";
		int n, g, m;
		cin >> n >> g >> m;
		vector<pair<int, int>> clockwiseGuest, antiGuest;
		for (int j = 0; j < g; j++)
		{
			int x;
			char c;
			cin >> x >> c;
			if (c == 'C')
				clockwiseGuest.emplace_back(make_pair(j, x));
			else
				antiGuest.emplace_back(make_pair(j, x));
		}
		cout << endl;
	}
	return 0;
}
