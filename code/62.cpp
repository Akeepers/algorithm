#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    system("pause");
    return 0;
}