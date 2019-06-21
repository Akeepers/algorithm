#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

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
            minLength = min(minLength, (int)item.length());
            maxLength = max(maxLength, (int)item.length());
        }
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = minLength; i < s.size(); ++i)
        {
            for (int len = minLength; len <= min(maxLength, i); ++len)
            {
                if(dp[i-len]&&dicts.count(s.substr(i-len,len)))
                    dp[i-1] = true;
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution solution;
    vector<string> inputs = {"apple", "pen"};
    solution.wordBreak("applepenapple", inputs);
    system("pause");
    return 0;
}
