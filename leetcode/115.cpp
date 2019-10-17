#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        if (m == 0 || m < n)
        {
            return 0;
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    system("pause");
    return 0;
}