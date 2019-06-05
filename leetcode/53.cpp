#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        int i = 0,ret=nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size();++i){
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            if(ret<dp[i])
                ret = dp[i];
        }
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}