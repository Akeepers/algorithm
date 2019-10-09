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

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

int seed = 13331;

typedef struct
{
	int len;
	vector<int> skills;
} Node;

ll myHash(vector<int> &vec)
{
	ll ret = 1;
	for (auto item : vec)
	{
		ret = ret * seed + item;
	}
	return ret;
}

bool check(vector<int> a, vector<int> b)
{
	unordered_set<int> items;
	for (auto i : a)
	{
		items.insert(i);
	}
	for (auto j : b)
	{
		if (!items.count(j))
			return false;
	}
	return true;
}

void slove()
{
	int n, s;
	cin >> n >> s;
	vector<Node> persons(n);
	unordered_map<ll, int> cnt;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		Node n;
		n.len = c;
		vector<int> kills(c);
		for (int j = 0; j < c; ++j)
		{
			cin >> kills[j];
		}
		sort(kills.begin(), kills.end());
		n.skills = vector<int>(kills);
		persons[i] = Node(n);
		for (int j = 1; j < (1 << c); ++j)
		{
			vector<int> sub;

			for (int k = 0; k < c; ++k)
			{
				if (j & (1 << k)) //判断j的第k位是否为1
					sub.emplace_back(kills[k]);
			}
			cnt[myHash(sub)]++;
		}
	}
	ll res = 0;
	sort(persons.begin(), persons.end(), [](const Node &a, const Node &b) { return a.len > b.len; });

	for (int i = 0; i < n; ++i)
	{
		auto hashVal = myHash(persons[i].skills);
		res += n - cnt[hashVal];
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
