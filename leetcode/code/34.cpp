#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    void getRange(vector<int> &nums, int index, vector<int> &ret)
    {
        int pos = index;
        int target = nums[index];
        while ((pos - 1) >= 0 && nums[pos - 1] == target)
            pos--;
        ret[0] = pos;
        pos = index;
        while ((pos + 1) < nums.size() && nums[pos + 1] == target)
            pos++;
        ret[1] = pos;
    }

  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret = {-1, -1};
        if (nums.empty())
            return ret;
        int low = 0;
        int high = nums.size() - 1;
        while(low<high){
            int mid=(low + high) / 2;
            if(nums[mid]==target){
                getRange(nums, mid, ret);
                return ret;
            }else if(nums[mid]<target)
                low = mid + 1;
            else
                high = mid - 1;

        }
        if (nums[low] == target)
            getRange(nums, low, ret);
        return ret;
    }
};
int main()
{
    system("pause");
    return 0;
}