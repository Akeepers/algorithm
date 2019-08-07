#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
const int seed = 23333;

struct Key
{
	char first, last;
	vector<int> freq;

	Key(const string& s)
	{
		freq.resize(26, 0);
		first = s.front();
		last = s.back();
		for (auto l : s)freq[l - 'a']++;
	}

	bool operator==(const Key& o) const
	{
		return (first == o.first && last == o.last &&
			freq == o.freq);
	}
};

namespace std
{
	template <>
	struct hash<Key>
	{
		size_t operator()(const Key& k) const
		{
			size_t ret = 17;
			ret = ret * seed + k.first;
			ret = ret * seed + k.last;
			for (auto l : k.freq)ret = ret * seed + l;
			return ret;
		}
	};
}

int charToAscii(char c)
{
	return c - 'a' + 97;
}

char asciiToChar(int num)
{
	return num - 97 + 'a';
}

int count(string& str, vector<string>& vecs)
{
	unordered_map<Key, int> dicts;
	set<ll> lengths;
	for (auto vec : vecs)
	{
		dicts[Key(vec)]++;
		lengths.insert(vec.length());
	}
	int res = 0;
	for (auto length : lengths)
	{
		if (length > str.length())
			continue;
		Key cur = Key(str.substr(0, length));
		if (dicts.count(cur))
		{
			res += dicts[cur];
			dicts.erase(cur);
		}
		for (int i = length; i < str.size(); ++i)
		{
			cur.freq[cur.first - 'a']--;
			cur.first = str[i - length + 1];
			cur.last = str[i];
			cur.freq[cur.last - 'a']++;
			if (dicts.count(cur))
			{
				res += dicts[cur];
				dicts.erase(cur);
			}
		}
	}
	return res;
}

string generateStr(char s1, char s2, ll n, ll a, ll b, ll c, ll d)
{
	auto x1 = charToAscii(s1), x2 = charToAscii(s2), x3 = 0;
	string ret(1, s1);
	ret.push_back(s2);
	for (int i = 3; i <= n; ++i)
	{
		x3 = (a * x2 + b * x1 + c) % d;
		ret += asciiToChar(97 + (x3 % 26));
		x1 = x2;
		x2 = x3;
	}
	return ret;
}

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		ll l, n, a, b, c, d;
		char s1, s2;
		cin >> l;
		vector<string> vecs(l);
		for (int j = 0; j < l; j++)
			cin >> vecs[j];
		cin >> s1 >> s2;
		cin >> n >> a >> b >> c >> d;
		string str = generateStr(s1, s2, n, a, b, c, d);
		auto res = count(str, vecs);
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
