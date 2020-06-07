#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void slove() {
    int n;
    cin >> n;
    vector<int> heights(n, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> heights[i - 1];
    }
    int res = 0, be = heights[0], af = heights[1];
    for (int i = 1; i < n - 1; ++i) {
        if (heights[i] > be && heights[i] < af) {
            res++;
        }
        if (i == n - 2) break;
        be = heights[i];
        af = heights[i + 2];
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
