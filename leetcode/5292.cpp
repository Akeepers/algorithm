#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
    bool check(vector<int> &nums, int begin, int end)
    {
        int last = nums[begin];
        for (int i = begin + 1; i < end; ++i)
        {
            if (last == nums[i] || last + 1 == nums[i])
            {
                last = nums[i];
            }
            else
                return false;
        }
        return true;
    }

public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        if (nums.size() % k != 0 || k < 1)
            return false;
        if (k == 1)
            return true;
        sort(nums.begin(), nums.end());
        int begin = 0, end = k;
        while (end <= nums.size())
        {
            if (!check(nums, begin, end))
                return false;
            end += k;
            begin += k;
        }
        return true;
    }
};

int main()
{
    vector<int> in = {16, 5, 15, 15, 20, 16, 20, 14, 21, 20, 19, 20, 12, 17, 13, 15, 11, 17, 18, 18, 11, 13, 13, 14, 14, 9, 20, 18, 10, 4, 4, 6, 15, 19, 8, 15, 7, 17, 15, 9, 24, 2, 23, 22, 26, 8, 21, 22, 14, 13, 16, 2, 25, 23, 17, 19, 17, 3, 22, 23, 19, 12, 21, 12, 16, 27, 28, 10, 13, 8, 24, 3, 22, 6, 10, 9, 14, 7, 11, 22, 11, 5, 16, 19, 21, 2, 8, 24, 16, 21, 7, 29, 18, 9, 10, 18, 6, 17, 21, 20};
    Solution s;
    s.isPossibleDivide(in, 10);
    system("pause");
    return 0;
}