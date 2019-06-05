#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1;
        int high = nums.size() - 1;
        do
        {
            int count = 0;
            int mid = (low + high) / 2;
            for (auto num:nums)
            {
                if (num <= mid)
                    count++;
            }
            if (count > mid)
                high = mid;
            else
                low = mid+1;
        } while (low < high);
        return low;
    }
};

int main()
{
    system("pause");
    return 0;
}
