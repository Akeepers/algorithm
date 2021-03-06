#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty() || k % nums.size() == 0)
            return;
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    system("pause");
    return 0;
}