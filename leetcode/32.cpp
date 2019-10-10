#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        if (n <= 1)
            return 0;
        vector<int> dp(n, 0);
        dp[1] = (s[1] == ')' && s[0] == '(') ? 2 : 0;
        auto res = dp[1];
        for (int i = 2; i < n; ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = dp[i - 2] + 2;
                else
                {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[1 - dp[i - 1] - 2] : 0);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main()
{
    string str = "()(())";
    Solution s;
    s.longestValidParentheses(str);
    system("pause");
    return 0;
}