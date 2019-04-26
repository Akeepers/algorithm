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
        for (int i = 0; i < n; ++i)
        {
            swap(nums[i], nums[(i + k) % n]);
        }
    }
};

int main()
{
    system("pause");
    return 0;
}