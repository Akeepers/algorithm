#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string res = "";
        if (nums.empty())
            return res;
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), [](const string &a, const string &b) { return a + b > b + a; });
        for (auto str : strs)
        {
            res += str;
        }
        return res[0]=='0'?"0":res;
    }
};

int main()
{
    system("pause");
    return 0;
}