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
const ll INF = 1e17;

string encode(char c, vector<int> &count)
{
	count[c - 'A']++;
	string res = "";
	for (auto item : count)
		res += 'A' + item;
	return res;
}
void slove()
{
	int l;
	cin >> l;
	string a, b;
	cin >> a >> b;
	unordered_set<string> strsOfB;
	for (int i = 0; i < l; ++i)
	{
		vector<int> tmp(26, 0);
		for (int j = i; j < l; ++j)
		{
			strsOfB.insert(encode(b[j], tmp));
		}
	}

	int res = 0;
	for (int i = 0; i < l; ++i)
	{
		vector<int> tmp(26, 0);
		for (int j = i; j < l; ++j)
		{
			auto str = encode(a[j], tmp);
			if (strsOfB.count(str))
				res++;
		}
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
