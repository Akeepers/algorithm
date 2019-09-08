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

vector<char> slove(vector<pair<ll, ll>> &slots, vector<pair<ll, ll>> &requests, ll d, ll s, ll sumCode, ll sumEate)
{
	vector<char> res(d);
	sort(slots.begin(), slots.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return (a.first + 1) / (float)(a.second + 1) > (b.first + 1) / (float)(b.second + 1);
	});
	float flag = sumCode / (float)sumEate;
	for (int i = 0; i < d; ++i)
	{
		if (requests[i].first > sumCode || requests[i].second > sumEate)
		{
			res[i] = 'N';
		}
		else if(requests[i].first == 0 )
		{
			res[i] = requests[i].second <= sumEate ? 'Y' : 'N';
		}else if (requests[i].second == 0 )
		{
			res[i] = requests[i].first <= sumCode ? 'Y' : 'N';
		}else if (requests[i].first/(float)requests[i].second>flag){
			ll cur1 = 0,pos=0;
			while(cur1<requests[i].first){
				cur1 += slots[pos++].first;
			}
			ll cur2=(cur1-requests[i].first)/(float)requests[i].first
		}
	}
}
int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ":";
		ll d, s;
		cin >> d >> s;
		vector<pair<ll, ll>> slots(s);
		vector<pair<ll, ll>> requests(d);
		ll sumCode = 0, sumEate = 0;
		for (ll j = 0; j < s; j++)
		{
			ll x1, x2;
			cin >> x1 >> x2;
			sumCode += x1;
			sumEate += x2;
			slots[j] = make_pair(x1, x2);
		}
		for (ll j = 0; j < d; j++)
		{
			ll x1, x2;
			cin >> x1 >> x2;
			requests[j] = make_pair(x1, x2);
		}
		cout << endl;
	}
	return 0;
}
