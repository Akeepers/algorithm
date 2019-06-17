#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res;
        if(s.empty())
            return res;
        unordered_set<string> dicts;
        for (auto item : wordDict)
        {
            dicts.insert(item);
        }
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n;++j){
                if(dicts.count(s.substr(i,j-i)))
                    dp[i][j] = true;
            }
        }
        if(dp[])
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
