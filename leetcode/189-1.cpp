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
        vector<int> vec(nums);
        for (int i = 0; i < n; ++i)
        {
            nums[(i + k) % n] = vec[i];
        }
    }
};

int main()
{
    system("pause");
    return 0;
}