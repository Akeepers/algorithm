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

ll count(ll d)
{
    ll cur = d;
    vector<int> bits;
    while (cur != 0)
    {
        auto bit = cur % 10;
        bits.emplace_back(bit);
        cur = cur / 10;
    }
    ll res = 0;
    auto n = bits.size();
    for (int i = n - 1; i >=0; --i)
    {
        if (i > 0)
            res += bits[i] * pow(9, i - 1) * 8;
        else
        {
            for (ll j = d - bits[i]; j <= d; ++j)
            {
                if (j % 9 > 0)
                    res++;
            }
        }
    }
    return res;
}

void slove()
{
    ll f, l;
    cin >> f >> l;
    auto res = count(l) - count(f) +1;
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