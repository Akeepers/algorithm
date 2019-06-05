#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
            return res;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            auto target = 0 - nums[i];
            int front = i + 1, back = nums.size() - 1;
            while (front < back)
            {
                auto sum = nums[front] + nums[back];
                if (sum > target)
                    back--;
                else if (sum < target)
                    front++;
                else
                {
                    res.emplace_back(vector<int>{nums[i], nums[front++], nums[back--]});
                    while (front < back && nums[front - 1] == nums[front])
                        front++;
                    while (front < back && nums[back + 1] == nums[back])
                        back--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}