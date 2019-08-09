#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,n=nums.size();
        while(i<n&&nums[i]!=val)
            i++;
        int j = i;
        for (; i < n; ++i)
        {
            if(nums[i]!=val)
                nums[j++] = nums[i];
        }
        return j;
    }
};

int main()
{
    system("pause");
    return 0;
}