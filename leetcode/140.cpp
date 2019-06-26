#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
private:
    void getPath(const vector<bool> &dp, vector<string> &res, const unordered_set<string> &dicts, string &s, string cur, int start, int minLength, int maxLength)
    {
        int length = s.size();
        for (int pos = start + minLength; pos <= min(start + maxLength, length); ++pos)
        {
            if (dp[pos] && dicts.count(s.substr(start, pos - start)))
            {
                if (pos == length)
                    res.emplace_back(cur + s.substr(start, pos - start));
                else
                    getPath(dp, res, dicts, s, cur + s.substr(start, pos - start) + " ", pos, minLength, maxLength);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dicts;
        vector<string> res;
        int minLength = INT_MAX, maxLength = 0;
        for (auto item : wordDict)
        {
            dicts.insert(item);
            minLength = min(minLength, (int)item.length());
            maxLength = max(maxLength, (int)item.length());
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = minLength; i <= s.size(); ++i)
        {
            for (int len = minLength; len <= min(maxLength, i); ++len)
            {
                if (dp[i - len] && dicts.count(s.substr(i - len, len)))
                    dp[i] = true;
            }
        }
        if (dp[s.size()])
        {
            getPath(dp, res, dicts, s, "", 0, minLength, maxLength);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "catsanddog";
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    solution.wordBreak(s, dict);
    system("pause");
    return 0;
}
