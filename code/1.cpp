#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indexs;
        int i = 0;
        vector<int> ret(0);
        for (auto num : nums)
        {
            auto temp = target - num;
            if (indexs.find(temp) != indexs.end())
            {
                    ret.push_back(i);
                    ret.push_back(indexs[temp]);
                    break;
            }
            if (indexs.find(num) == indexs.end())
                indexs.insert({num, i});
            i++;
        }
        return ret;
    }
};

int main()
{

    return 0;
}
