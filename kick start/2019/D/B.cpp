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

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ":";
		int n, g, m;
		cin >> n >> g >> m;
		vector<vector<int>> consulates(n, vector<int>(1, 0));
		vector<pair<int,int>> clockwiseGuest, antiGuest;
		for (int j = 0; j < g; j++)
		{
			int x;
			char c;
			cin >> x >> c;
			if (c == 'C')
				clockwiseGuest.emplace_back(make_pair(j,x));
			else
				antiGuest.emplace_back(make_pair(j,x));
		}
		int pos;
		for (auto item : clockwiseGuest)
		{
			pos = (item.second + m) % n;
			consulates[pos][0]=m;
			consulates[pos].emplace_back(item.first);
		}
		for (int i = pos - 1; i != pos; i = (i - 1 + m) % n)
		{
		}
		cout << endl;
	}
	return 0;
}
