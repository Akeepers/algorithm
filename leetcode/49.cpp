#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
private:
    bool isSame(unordered_map<char, int> &count1, unordered_map<char, int> &count2)
    {
        if (count1.size() != count2.size())
            return false;
        for (auto item : count1)
        {
            if (count2.count(item.first) == 0 || count2[item.first] != item.second)
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> res;
        if (strs.empty())
            return res;
        sort(strs.begin(), strs.end(), [](string a, string b) -> bool { return a.size() < b.size(); });

        unordered_map<char, int> lastCount;
        string last = strs[0];
        for (auto c : strs[0])
        {
            if (lastCount.count(c))
                lastCount[c]++;
            else
                lastCount[c] = 0;
        }
        vector<string> cur = {last};
        if (strs.size() == 1)
        {
            res.emplace_back(cur);
            return res;
        }
        for (int i = 1; i < strs.size(); ++i)
        {
            unordered_map<char, int> curCount;
            for (auto c : strs[i])
            {
                if (curCount.count(c))
                    curCount[c]++;
                else
                    curCount[c] = 0;
            }
            if (strs[i].size() != last.size() || isSame(lastCount, curCount))
            {
                res.emplace_back(cur);
                cur.resize(0);
            }
            cur.emplace_back(strs[i]);
            last = strs[i];
            lastCount = curCount;
        }
        return res;
    }
};

int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    solution.groupAnagrams(input);
    system("pause");
    return 0;
}