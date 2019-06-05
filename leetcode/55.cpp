#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.empty())
            return true;
        int lastIndex = nums.size() - 1;
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (maxIndex < i)
                return false;
            maxIndex = max(i + nums[i], maxIndex);
        }
        return maxIndex >= lastIndex;
    }
};

int main()
{
    system("pause");
    return 0;
}
