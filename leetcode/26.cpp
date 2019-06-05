#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int pos = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] != nums[i + 1])
                nums[pos++] = nums[i];
        }
        nums[pos++] = nums[nums.size() - 1];
        return pos;
    }
};

int main()
{
    system("pause");
    return 0;
}
