#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;
        int lastIndex = nums.size() - 1;
        int end = 0, start = 0, step = 0, maxIndex = 0;
        while (end < lastIndex)
        {
            step++;
            for (int i = start; i <= end; ++i)
            {
                if (i + nums[i] >= lastIndex)
                    return step;
                maxIndex = max(i + nums[i], maxIndex);
            }
            start = end + 1;
            end = maxIndex;
        }
        return step;
    }
};
int main()
{
    vector<int> inputs = {2, 3, 1, 1, 4};
    Solution solution;
    return solution.jump(inputs);
    system("pause");
    return 0;
}
