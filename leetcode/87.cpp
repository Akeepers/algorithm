#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        if (m != n)
            return false;
        if (m == 1)
            return s1 == s2;
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        //初始化，边界情况
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        //枚举
        for (int l = 2; l <= n; ++l)
        {
            for (int i = 0; i + l <= n; ++i)
            {
                for (int j = 0; j + l <= n; ++j)
                {
                    for (int k = 1; k <= l; ++k)
                    {
                        dp[l][i][j] = (dp[k][i][j] && dp[l - k][i + k][j + k]) || (dp[k][i][j + l - k] && dp[l - k][i + k][j]);
                        if (dp[l][i][j])
                            break;
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};

int main()
{
    system("pause");
    return 0;
}