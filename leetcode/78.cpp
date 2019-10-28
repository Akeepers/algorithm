#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        auto n=nums.size();
        if(nums.empty())
            return res;
        for(int i=0;i<(1<<n);++i){
            vector<int> sub;
            for(int j=0;j<n;++j){
                if(i&(1<<j))
                    sub.emplace_back(nums[j]);
            }
            res.emplace_back(sub);
        }
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}
