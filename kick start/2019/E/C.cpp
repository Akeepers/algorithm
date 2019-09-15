#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

namespace Prime
{
default_random_engine e;
long long power_mod(long long x, long long n, long long mod)
{
	long long ret = 1;
	while (n)
	{
		if (n & 1)
			ret = x * ret % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ret;
}
long long mulmod(long long x, long long y, long long n)
{
	return x * y % n;
}
bool witness(long long a, long long n, long long u, long long t)
{
	long long x0 = power_mod(a, u, n), x1;
	for (int i = 1; i <= t; ++i)
	{
		x1 = mulmod(x0, x0, n);
		if (x1 == 1 && x0 != 1 && x0 != n - 1)
			return false;
		x0 = x1;
	}
	if (x1 != 1)
		return false;
	return true;
}

bool miller_rabin(long long n, int times = 20)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (!(n & 1))
		return false;
	long long u = n - 1, t = 0;
	while (u % 2 == 0)
	{
		t++;
		u >>= 1;
	}
	uniform_int_distribution<long long> rand(1, n - 1);
	while (times--)
	{
		long long a = rand(e);
		if (!witness(a, n, u, t))
			return false;
	}
	return true;
}
}; // namespace Prime

bool isPrime(ll x)
{
	return x == 1 || Prime::miller_rabin(x);
}

void slove()
{
	ll l, r;
	cin >> l >> r;
	int res = 0;
	for (ll i = l; i <= r; ++i)
	{
		ll cnt = 0;
		ll cur = i;
		while (cur % 2 == 0)
		{
			cnt++;
			cur /= 2;
		}
		if (cnt == 1)
		{
			res++;
		}
		else if (cnt == 0 || cnt == 2)
		{
			if (isPrime(cur))
				res++;
		}
		else if (cnt == 3)
		{
			if (cur == 1)
				res++;
		}
		else
		{
			continue;
		}
	}
	cout << res << endl;
}
int main()
{
	auto t = 0;
	cin >> t;
	for (ll i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
	}
	return 0;
}
