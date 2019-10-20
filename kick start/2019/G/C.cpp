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

ll utity(vector<ll>& a, vector<ll>& b, int n, int h)
{
	ll res = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
		{
			ll t1 = 0, t2 = 0;
			for (int k = 0; k < n; ++k)
			{
				bool f1 = i & (1 << k), f2 = j & (1 << k);
				if(!f1&&!f2){
					t1 = h - 1;
					break;
				}
				if (i & (1 << k))
				{
					f1 = true;
					t1 += a[k];
				}
				if (j & (1 << k))
				{
					t2 += b[k];
					f2 = true;
				}
				if (f1 || f2)
					continue;;
				t1 = h - 1;
				break;
			}
			if (t1 >= h && t2 >= h)
				res++;
		}
	}
	return res;
}

void slove()
{
	int n, h;
	cin >> n >> h;
	vector<ll> a(n, 0), b(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	auto res = utity(a, b, n, h);
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
