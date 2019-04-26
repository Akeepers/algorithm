#include <iostream>
#include <vector>
#include <algorithm>

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
        reverse(nums, nums + n - k);
    }
};

int main()
{
    system("pause");
    return 0;
}