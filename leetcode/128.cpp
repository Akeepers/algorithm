#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

//hash table
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> records(nums.begin(), nums.end());
        int res = 0;
        for (auto num : nums)
        {
            if (!records.count(num))
                continue;
            records.erase(num);
            auto pre = num - 1, next = num + 1;
            while (records.count(pre))
                records.erase(pre--);
            while (records.count(next))
                records.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

int main()
{

    string begin = "hit";
    string end = "cog";
    vector<string> list = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution solution;
    solution.ladderLength(begin, end, list);
    system("pause");
    return 0;
}
