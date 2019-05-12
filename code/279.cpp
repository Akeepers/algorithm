#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        if (n < 1)
            return 0;
        static vector<int> dp = {0};
        while (dp.size() <= n)
        {
            int cur = INT_MAX;
            int i = dp.size();
            for (int j = 1; j * j <= i; ++j)
            {
                cur = min(cur, dp[i - j * j] + 1);
            }
            dp.emplace_back(cur);
        }
        return dp[n];
    }
};

int main()
{
    system("pause");
    return 0;
}
