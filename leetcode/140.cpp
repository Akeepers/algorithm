#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
private:
    void getPath(const vector<int> &dp, vector<string> &res, const unordered_set<string> &dicts, string &s, string cur, int start, int minLength, int maxLength)
    {
        int length = s.size();
        if (start == length)
            res.emplace_back(cur);
        else
        {
            if (start + minLength > length)
                return;
            else
            {
                int end = start + maxLength > length ? length : start + maxLength;
                for (int i = start + minLength - 1; i < end; ++i)
                {
                    if (dp[i])
                    {
                        auto word = s.substr(start, i - start + 1);
                        if (dicts.count(word))
                        {
                            auto next = cur == "" ? word : cur + " " + word;
                            getPath(dp, res, dicts, s, next, i + 1, minLength, maxLength);
                        }
                    }
                }
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res;
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
        vector<int> dp(s.size(), false);
        dp[0] = true;
        for (int i = minLength; i < s.size(); ++i)
        {
            for (int len = minLength; len <= min(maxLength, i); ++len)
            {
                if(dp[i-len]&&dicts.count(s.substr(i-len,len)))
                    dp[i-1] = true;
            }
        }
        getPath(dp, res, dicts, s, "", 0, minLength, maxLength);
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
