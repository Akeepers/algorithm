#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i > 10)
            {
                dp[n - 1] = dp[i - 1];
                break;
            }
            int cnt = 9, cur = i, mul = 9;
            while (--cur)
            {
                cnt *= mul--;
            }
            dp[i] = dp[i - 1] + cnt;
        }
        return dp[n];
    }
};

int main()
{
    system("pause");
    return 0;
}