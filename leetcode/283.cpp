#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return;
        int p1 = 0, p2 = 0;
        while (p2 < nums.size() && p1 < nums.size())
        {
            while (p1 < nums.size() && nums[p1] != 0)
            {
                p1++;
            }
            if (p1 >= nums.size() - 1)
                break;
            p2 = p1 + 1;
            while (p2 < nums.size() && nums[p2] == 0)
            {
                p2++;
            }
            if (p2 >= nums.size())
                break;
            swap(nums[p1], nums[p2]);
            p1++;
            p2++;
        }
    }
};

class Solution2
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                nums[j++]=nums[i];
            }
        }
        while(j<nums.size())
            nums[j++]=0;
    }
};

int main()
{
    system("pause");
    return 0;
}