#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for(auto num:nums){
            if(visited.count(num))
                return true;
            visited.insert(num);
        }
        return false;
    }
};
int main()
{
    system("pause");
    return 0;
}