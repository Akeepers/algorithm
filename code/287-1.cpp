#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        int result = 0;
        for(auto num:nums){
            if(set.find(num)!=set.end()){
                result = num;
                break;
            }else{
                set.insert(num);
            }
                
        }
        return result;
    }
};

int main(){
    system("pause");
    return 0;
}
