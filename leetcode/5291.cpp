#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(auto num:nums){
            auto str=to_string(num);
            if(str.size()%2==0)
                res++;
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}