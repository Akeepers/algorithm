#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);
        int index = 1;
        for (int i = 1; i <= num; ++i)
        {
            if ((i & 1) == 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            else if ((i == (1 << index)))
            {
                dp[i] = 1;
                index++;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp;
    }
};

int main()
{
    system("pause");
    return 0;
}