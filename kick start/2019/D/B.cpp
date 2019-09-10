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

typedef struct Node
{
	int pos, dir, cnt;
	vector<int> ids;
} Guest;

vector<int> solve(int n, int m, int g, vector<pair<int, int>> &clockwiseGuest, vector<pair<int, int>> &antiGuest)
{
	vector<int> consulates(n, -1);
	vector<Guest> groups;
	vector<vector<int>> guests(n * 2);
	int pos;
	for (auto guest : clockwiseGuest)
	{
		pos = getMod(guest.second + m, n);
		guests[pos].emplace_back(guest.first);
	}
	for (auto guest : antiGuest)
	{
		pos = getMod(guest.second - m, n);
		guests[pos + n].emplace_back(guest.first);
	}
	for (int i = 0; i < n * 2; ++i)
	{
		if (guests[i].empty())
			continue;
		if (i < n)
		{
			groups.emplace_back(Guest{i, -1, 0, guests[i]});
		}
		else
		{
			groups.emplace_back(Guest{i - n, 1, 0, guests[i]});
		}
	}
	int visited = 0;
	m = m > n ? n : m; 
	for (int time = m; time >= 0 && visited < n; --time)
	{
		for (int i = 0; i < groups.size(); ++i)
		{
			pos = groups[i].pos;
			if (consulates[pos] < time)
			{
				visited++;
				consulates[pos] = time;
			}
			if (consulates[pos] == time)
				groups[i].cnt++;
			groups[i].pos = getMod(pos + groups[i].dir, n);
		}
	}

	vector<int> res(g, 0);
	for (auto group : groups)
	{
		for (auto id : group.ids)
		{
			res[id] = group.cnt;
		}
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
		auto res = solve(n, m, g, clockwiseGuest, antiGuest);
		cout << "Case #" << i << ":";
		for (auto item : res)
			cout << " " << item;
		cout << endl;
	}
	return 0;
}
