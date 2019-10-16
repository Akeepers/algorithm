#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        long long m = triangle.size(), res = INT_MAX;
        if (m == 0)
            return 0;
        vector<vector<long long>> dp(2, vector<long long>(m, INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[1][j] = min(dp[0][j], j > 0 ? dp[0][j - 1] : INT_MAX) + triangle[i][j];
            }
            dp[0] = dp[1];
        }
        for (auto item : dp[0])
        {
            res = min(res, item);
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}