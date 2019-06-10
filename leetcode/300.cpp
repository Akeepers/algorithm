#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int n = nums.size();
        int length = 1;
        vector<int> tails(n, 0);
        tails[0] = nums[0];
        for (int i = 0; i < n; ++i)
        {
            if (tails[0] > nums[i])
                tails[0] = nums[i];
            else if (nums[i] > tails[length - 1])
                tails[length++] = nums[i];
            else
            {
                auto it = std::lower_bound(tails.begin(), tails.begin() + length, nums[i]);
                *it = nums[i];
            }
        }
        return length;
    }
};

int main()
{
    system("pause");
    return 0;
}