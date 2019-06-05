#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n < 3)
            return 0;
        int ret = 0;
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>maxLeft)
                    maxLeft = height[left];
                else
                    ret += maxLeft - height[left];
                left++;
            }else{
                if(height[right]>maxRight)
                    maxRight = height[right];
                else
                    ret += maxRight - height[right];
                right--;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    vector<int> inputs = {5, 4, 1, 2};
    cout << solution.trap(inputs) << endl;
    system("pause");
    return 0;
}