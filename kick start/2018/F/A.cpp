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

void slove()
{
	int l;
	cin >> l;
	string a, b;
	cin >> a >> b;
	vector<vector<vector<int>>> countA(l, vector<vector<int>>(l, vector<int>(26, 0)));
	vector<vector<vector<int>>> countB(l, vector<vector<int>>(l, vector<int>(26, 0)));
	for (int i = 0; i < l; ++i)
	{
		for (int j = i; j < l; ++j)
		{
			countA[make_pair(i, j)] = vector<int>(26, 0);
		}
	}
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
