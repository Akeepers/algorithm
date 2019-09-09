#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

int getMod(int a, int b)
{
	double c = floor(a / (double)b);

	auto tmp = a - c * b;
	return tmp;
}

vector<int> solve(int n, int m, int g, vector<pair<int, int>> &clockwiseGuest, vector<pair<int, int>> &antiGuest)
{
	vector<int> times1(n, 0), times2(n, 0);
	vector<vector<int>> consulates(n);
	vector<pair<int, vector<int>>> consulates2(n);
	vector<int> res(g, 0);
	int pos, last, step;
	if (!clockwiseGuest.empty())
	{
		for (auto guest : clockwiseGuest)
		{
			pos = getMod(guest.second + m, n);
			times1[pos] = m;
			consulates[pos].emplace_back(guest.first);
		}
		last = pos;
		step = 0;
		for (int i = getMod(pos - 1, n); i != pos; i = getMod(i - 1, n))
		{
			if (times1[i] == m)
			{
				last = i;
				step = 0;
			}
			else
			{
				step++;
				if (step > m)
					continue;
				times1[i] = m - step;
				consulates[i] = vector<int>(consulates[last]);
			}
		}
	}
	if (!antiGuest.empty())
	{
		for (auto guest : antiGuest)
		{
			pos = getMod(guest.second - m, n);
			times2[pos] = m;
			if (times1[pos] == m)
			{
				consulates[pos].emplace_back(guest.first);
			}
			else
			{
				consulates[pos] = vector<int>{guest.first};
			}
		}
		last = pos;
		step = 0;
		for (int i = getMod(pos + 1, n); i != pos; i = getMod(i + 1, n))
		{

			if (times2[i] == m)
			{
				last = i;
				step = 0;
				continue;
			}
			step++;
			if (step > m)
				continue;
			auto curTime = m - step;
			if(curTime==times1[i])
			{
				consulates2[i].second = vector<int>(consulates2[last].second);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (auto guest : consulates[i])
			res[guest]++;
	}
	return res;
}

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{

		int n, g, m;
		cin >> n >> g >> m;
		vector<pair<int, int>> clockwiseGuest, antiGuest;
		for (int j = 0; j < g; j++)
		{
			int x;
			char c;
			cin >> x >> c;
			if (c == 'C')
				clockwiseGuest.emplace_back(make_pair(j, x - 1));
			else
				antiGuest.emplace_back(make_pair(j, x - 1));
		}
		m = n + m % n;
		auto res = solve(n, m, g, clockwiseGuest, antiGuest);
		cout << "Case #" << i << ":";
		for (auto item : res)
			cout << " " << item;
		cout << endl;
	}
	return 0;
}
