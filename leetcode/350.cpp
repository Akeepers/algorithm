#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> dict;
        for(auto num:nums1){
            dict[num]++;
        }
        vector<int> res;
        for(auto num:nums2){
            if(dict.count(num)){
                res.emplace_back(num);
                if(--dict[num]==0)
                    dict.erase(num);
            }
            if(dict.empty())
                break;
        }
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}