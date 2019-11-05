#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums;
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, 0);
        int m = 1, pos = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] % nums[i] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                        if (dp[i] > m)
                        {
                            m = dp[i];
                            pos = i;
                        }
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < m; ++i)
        {
            res.emplace_back(nums[pos]);
            pos = pre[pos];
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}