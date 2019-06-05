#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() < 2)
            return s.size();
        unordered_map<char, int> indexs;
        indexs[s[0]] = 0;
        int dp[s.size()] = {1};
        int length = 1;
        dp[0] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (indexs.find(s[i]) == indexs.end() || i - indexs[s[i]] > dp[i - 1])
                {
                    dp[i] = dp[i - 1] + 1;
                }
            else
            {
                dp[i] = i - indexs[s[i]];
            }
            indexs[s[i]] = i;
            length = max(length, dp[i]);
        }

        return length;
    }
};

int main()
{
    Solution solution;
    solution.lengthOfLongestSubstring("abcabcbb");
    system("pause");
    return 0;
}