#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;
        for (auto& str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].emplace_back(str);
        }

        for (auto& item : mp)
        {
            res.emplace_back(item.second);
        }
        return res;
    }
};

class Solution2
{
private:
    string stringSort(string &str)
    {
        vector<int> count(26, 0);
        for (auto& c : str)
        {
            count[c - 'a']++;
        }
        string res = "";
        for (auto& item : count)
        {
            res += item + 'a';
        }
        return res;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;
        for (auto& str : strs)
        {
            mp[stringSort(str)].emplace_back(str);
        }

        for (auto& item : mp)
        {
            res.emplace_back(item.second);
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