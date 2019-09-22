#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Solution
{
    ll lcm(ll a,ll b){
        return a * b / __gcd(a, b);
    }

public:
   int nthUglyNumber(int n, int a, int b, int c)
	{
        if(a>b)
            swap(a, b);
        if(b>c)
            swap(b, c);
        if(a>b)
            swap(a, b);
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(a, bc);
        ll l = 0, r = 2e9;
        while(l<r){
            auto mid = (l + r) / 2;
            ll cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if(cnt<n)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    system("pause");
    return 0;
}