#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        int finder = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        while (true)
        {
            slow = nums[slow];
            finder = nums[finder];
            if (slow == finder)
                return slow;
        }
    }
};

int main()
{
    system("pause");
    return 0;
}
