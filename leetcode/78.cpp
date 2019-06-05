#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        ret.emplace_back(vector<int>(0));
        if (nums.empty())
            return ret;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            vector<int> vec;
            for (; i + step <= n; i++)
            {
                ret.emplace_back(vector<int>(nums.begin() + i, nums.begin() + i + step));
            }
            step++;
        }
        return ret;
    }
};
int main()
{
    system("pause");
    return 0;
}
