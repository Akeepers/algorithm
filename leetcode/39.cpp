#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void build(vector<int> &candidates, int pos, int target, vector<int> cur, vector<vector<int>>& res)
    {
        if (pos == candidates.size())
            return;
        if (candidates[pos] > target)
            build(candidates, pos + 1, target, cur, res);
        else if(candidates[pos]==target)
        {
            cur.emplace_back(candidates[pos]);
            res.emplace_back(cur);
            cur.clear();
            build(candidates, pos + 1,target - candidates[pos], cur, res);
        }else{
            cur.emplace_back(candidates[pos]);
            build(candidates, pos, target-candidates[pos], cur, res);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end(), greater<int>());
        if(candidates.empty()||candidates.back()<target)
            return res;
        vector<int> cur;
        build(candidates, 0, target, cur, res);
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}