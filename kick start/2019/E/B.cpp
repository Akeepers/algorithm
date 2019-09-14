#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
const double EPS = 2e-8;

typedef struct
{
	ll code, eat, id;
	char res;
} Node;

void slove()
{
	ll d, s;
	cin >> d >> s;
	vector<pair<ll, ll>> slots(s);
	vector<Node> requests(d);
	vector<ll> sumCode(s + 1, 0), sumEat(s + 1, 0);
	for (ll i = 0; i < s; i++)
		cin >> slots[i].first >> slots[i].second;

	sort(slots.begin(), slots.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) { return a.first * b.second > a.second * b.first; });

	for (ll i = 0; i < d; i++)
	{
		cin >> requests[i].code >> requests[i].eat;
		requests[i].id = i;
	}

	sort(requests.begin(), requests.end(), [](const Node &a, const Node &b) { return a.code < b.code; });
	for (ll i = 1; i <= s; ++i)
		sumCode[i] = slots[i - 1].first + sumCode[i - 1];
	for (ll i = s - 1; i >= 0; --i)
		sumEat[i] = slots[i].second + sumEat[i + 1];

	vector<char> res(d);
	for (ll i = 0, pos = 0; pos < d; ++pos)
	{
		auto &cur = requests[pos];
		while (i < s - 1 && sumCode[i + 1] < cur.code)
			i++;
		if (sumCode[i + 1] >= cur.code && sumEat[i + 1] >= cur.eat)
			cur.res = 'Y';
		else
		{
			auto code = cur.code - sumCode[i];
			auto eat = cur.eat - sumEat[i + 1];
			if (slots[i].first < code || slots[i].second < eat)
				cur.res = 'N';
			else if (slots[i].first == 0)
				cur.res = slots[i].second >= eat ? 'Y' : 'N';
			else
			{
				double f = code / ((double)slots[i].first + EPS);
				cur.res = (1 - f) * slots[i].second + DBL_MIN >= eat ? 'Y' : 'N';
			}
		}
	}
	sort(requests.begin(), requests.end(), [](const Node &a, const Node &b) { return a.id < b.id; });

	for (auto item : requests)
		cout << item.res;
}
int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
		cout << endl;
	}
	return 0;
}
