#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        long minPre = nums[0], maxPre = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int temp1 = minPre * nums[i];
            int temp2 = maxPre * nums[i];
            maxPre = max(max(temp1,temp2), nums[i]);
            minPre = min(min(temp1,temp2), nums[i]);
            res = max(res, maxPre);
        }
        return res;
    }
};

int main()
{
    vector<int> input = {-4, -3, -2};
    Solution s;
    s.maxProduct(input);
    system("pause");
    return 0;
}