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
        int start = 0;
        while (n && (k %= n))
        {
            for (int i = 0; i < k; ++i)
            {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            start += k;
            n -= k;
        }
    }
};

int main()
{
    system("pause");
    return 0;
}