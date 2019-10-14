#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int len = 0;
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                len = 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                len = 1;
            }
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }
        return len * len;
    }
};

int main()
{
    system("pause");
    return 0;
}