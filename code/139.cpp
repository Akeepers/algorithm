#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dicts;
        for (auto item : wordDict)
        {
            dicts.insert(item);
        }
        vector<int> dp(s.size(), false);
        if (dicts.find(string(1, s[0])) != dicts.end())
            dp[0] = true;
        for (int i = 1; i < s.size(); ++i)
        {
            auto word = s.substr(0, i + 1);
            if (dicts.find(word) != dicts.end())
            {
                dp[i] = true;
                continue;
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    word = s.substr(j, i - j);
                    if (dicts.find(word) != dicts.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution solution;
    vector<string> inputs = {"a"};
    solution.wordBreak("a", inputs);
    system("pause");
    return 0;
}
