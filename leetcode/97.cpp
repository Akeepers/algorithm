#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l)
            return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i)
        {
            if (s3[i - 1] != s1[i - 1])
                break;
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (s3[i - 1] != s2[i - 1])
                break;
            dp[0][i] = true;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
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