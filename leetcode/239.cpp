#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.empty())
            return res;
        int pre = nums[0], curMax = nums[0], n = nums.size();
        int i = 0;
        while (i < k && i < n)
        {
            curMax = max(curMax, nums[i++]);
        }
        res.emplace_back(curMax);
        if (i>=n)
            return res;
        for(;i)
            
    }
};

int main()
{
    system("pause");
    return 0;
}