#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

void slove() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1), nums1(n + 1), nums2(n + 1);
    vector<int> sums(n + 1, 0), sums1(n + 1, 0), sums2(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        // sums[i] = sums[i - 1] + nums[i];
        // if (i & 1) {
        //     nums1[i] = -2 * nums[i];
        //     nums2[i] = 0;
        // } else {
        //     nums2[i] = -2 * nums[i];
        //     nums1[i] = 0;
        // }
        // sums1[i] = sums1[i - 1] + nums1[i];
        // sums2[i] = sums2[i - 1] + nums2[i];
    }
    int res = 0;
    for (int i = 0; i < q; ++i) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'Q') {
            int k = 1, cur = 0;
            for (int j = x; j <= y; ++j) {
                cur += k * nums[j] * (j - x + 1);
                k *= -1;
            }
            res += cur;
        } else {
            nums[x] = y;
        }
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
    system("pause");
    return 0;
}
