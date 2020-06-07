#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define INF 1e8

class Solution {
   public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
                int target) {
        unordered_set<int> items;
        for (auto& house : houses) {
            if (house != 0) items.insert(house);
        }
        if (items.size() > target) return -1;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n + 1, vector<int>(target + 1, INF)));
        if (houses[0] == 0) {
            for (int i = 1; i <= n; ++i) {
                dp[0][i][1] = cost[0][i - 1];
            }
        } else {
            dp[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= target; ++k) {
                        dp[i][j][k] =
                            min(dp[i - 1][j][k] + cost[i][j - 1], dp[i][j][k]);
                        for (int j1 = 1; j1 <= n; ++j1) {
                            if (j1 == j) continue;
                            dp[i][j][k] =
                                min(dp[i - 1][j1][k - 1] + cost[i][j - 1],
                                    dp[i][j][k]);
                        }
                    }
                }
            } else {
                auto j = houses[i];
                for (int k = 1; k <= target; ++k) {
                    dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
                    for (int j1 = 1; j1 <= n; ++j1) {
                        if (j1 == j) continue;
                        dp[i][j][k] = min(dp[i - 1][j1][k - 1], dp[i][j][k]);
                    }
                }
            }
        }
        int res = INF;
        for (int i = 1; i <= n; ++i) {
            res = min(res, dp[m - 1][i][target]);
        }
        return res == INF ? -1 : res;
    }
};

int main() {
    system("pause");
    return 0;
}