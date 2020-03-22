#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void slove() {
    int n, b;
    cin >> n >> b;
    vector<int> costs(n, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i - 1];
    }
    sort(costs.begin(), costs.end());
    int res = 0, cur = 0;
    for (auto cost : costs) {
        cur += cost;
        if (cur > b) break;
        res++;
    }
    cout << res << endl;
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
