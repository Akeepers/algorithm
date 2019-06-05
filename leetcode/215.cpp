#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  private:
    int partition(vector<int> &nums, int begin, int end)
    {
        if (begin >= end)
            return 0;
        int pivot = nums[begin];
        int i = begin, j = end;
        while (i < j)
        {
            while (nums[j] >= pivot && i < j)
                j--;
            while (nums[i] <= pivot && i < j)
                i++;
            if (i == j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[begin]);
        return i;
    }

  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int begin=0;
        int end = nums.size()-1;
        int index = nums.size() - k ;
        while(begin<end){
            int p = partition(nums, begin, end);
            if(p==index)
                break;
            if(p<index)
                begin = p + 1;
            if(p>index)
                end = p - 1;
        }
        return nums[index];
    }
};

int main()
{
    vector<int> inputs = {3, 2, 1, 5, 6, 4};
    Solution solution;
    cout<<solution.findKthLargest(inputs, 2)<<endl;
    system("pause");
    return 0;
}