#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

class Solution {
   public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3) return false;
        int n = A.size();
        vector<int> sum(n, 0);
        sum[0] = A[0];
        for (int i = 1; i < n; ++i) {
            sum[i] += sum[i - 1] + A[i];
        }
        if (sum[n - 1] % 3 != 0) return false;
        int d = sum[n - 1] / 3;
        int cur = d, cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (cur == sum[i]) {
                if (cnt == 1)
                    cur = d * (++cnt);
                else
                    return i != n - 1;
            }
        }
        return false;
    }
};
int main() {
    vector<int> inputs = {10, -10, 10, -10, 10, -10, 10, -10};
    Solution s;
    s.canThreePartsEqualSum(inputs);
    system("pause");
    return 0;
}