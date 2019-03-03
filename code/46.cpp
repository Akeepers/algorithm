#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    void getOrder(vector<vector<int>>& result,vector<int> currentNums,int low,int high){
        if(low==high){
            result.push_back(currentNums);
            return;
        }
        for(int i=0;i<=low;++i){
            swap(currentNums[i],currentNums[low]);
            getOrder(result,currentNums,low+1,high);
            swap(currentNums[i],currentNums[low]);
        }     
    }
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getOrder(result,nums,1,nums.size());
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> input={1,2,3};
    auto result=solution.permute(input);
    for(auto vec:result){
        for(auto item:vec){
            cout<<item<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}