#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

//in-place 算法
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] != i && nums[i] != n)
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};

//位运算
class Solution1
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            res = res ^ i ^ nums[i];
        }
        return res ^ n;
    }
};

int main()
{
    system("pause");
    return 0;
}