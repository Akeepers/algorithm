#include <algorithm>
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
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector(n, INT_MAX));
        int curMax = -1;
        for (int i = 0; i < n; ++i) {
            curMax = max(jobDifficulty[i], curMax);
            dp[0][i] = curMax;
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < n; ++j) {
                int localMax = jobDifficulty[j];
                for (int k = j; k >= i; --k) {
                    localMax = max(localMax, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + localMax);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};

int main() {
    system("pause");
    return 0;
}