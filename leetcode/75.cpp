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
    void sortColors(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid<=high){
            if(nums[mid]==0)
            {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                mid++;
                high--;
            }else{
                mid++;
            }
        }
    }
};

int main()
{
    system("pause");
    return 0;
}