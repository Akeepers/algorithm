#include <climits>
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
        int minLength = INT_MAX, maxLength = 0;
        for (auto item : wordDict)
        {
            dicts.insert(item);
            if (item.size() < minLength)
                minLength = item.size();
            if (item.size() > maxLength)
                maxLength = item.size();
        }
        vector<bool> dp(s.size(), false);
        if (dicts.count(s.substr(0, minLength)))
            dp[minLength - 1] = true;
        for (int i = minLength; i < s.size(); ++i)
        {
            if (dicts.count(s.substr(0, i + 1)))
                dp[i] = true;
            else
            {
                int end = i - maxLength >= 0 ? i - maxLength : 0;
                for (int j = i - minLength; j >= end; --j)
                {
                    if (dp[j] && dicts.count(s.substr(j + 1, i - j)))
                    {
                        dp[i] = true;
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
    vector<string> inputs = {"apple","pen"};
    solution.wordBreak("applepenapple", inputs);
    system("pause");
    return 0;
}
