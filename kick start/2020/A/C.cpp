#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool is_sussess(vector<ll>& times, ll target, ll k) {
    ll cur = 0;
    for (int i = 1; i < times.size(); ++i) {
        ll cur_diff = llabs(times[i] - times[i - 1]);
        if (cur_diff > target) {
            cur += cur_diff / target;
            if (cur_diff % target == 0) {
                cur--;
            }
        }
        if (cur > k) return false;
    }
    return true;
}

void slove() {
    ll n, k;
    cin >> n >> k;

    vector<ll> times(n, 0);
    ll max_diff = 0;
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
        if (i == 0) continue;
        max_diff = max(max_diff, llabs(times[i] - times[i - 1]));
    }
    ll l = 1, r = max_diff;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (is_sussess(times, mid, k)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << l << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        slove();
    }
    return 0;
}
