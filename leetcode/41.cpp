#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
            return 1;
        int n = nums.size();
        int res = n + 1;
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}