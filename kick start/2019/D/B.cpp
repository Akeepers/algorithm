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
		cin >> n >> g>>m;
		vector<int>
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			if (xorOdd[x])
				indexs.insert(j);
		}
		for (int j = 0; j < q; j++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			if (indexs.count(tmp1))
				indexs.erase(tmp1);
			if (xorOdd[tmp2])
				indexs.insert(tmp1);
			if (indexs.size() % 2 == 0)
				cout << " " << n;
			else
			{
				int r = *indexs.rbegin();
				int l = *indexs.begin();
				cout<<" "<<max(r, n - l - 1);
			}
		}
		cout << endl;
	}
	return 0;
}
