#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        if (s.size() < k)
            return 0;
        int n = s.size();
        int res = 0;
        for (int begin = 0; begin + k <= n;)
        {
            vector<int> count(26, 0);
            int isAllMatch = 0;
            int end = begin;
            int maxEnd = begin;
            for (; end < n; ++end)
            {
                int cur = s[end] - 'a';
                count[cur]++;
                if (count[cur] >= k)
                    isAllMatch &= (~(1 << cur));
                else
                    isAllMatch |= (1 << cur);

                //catch a substring which meets the condition.
                if (isAllMatch == 0)
                {
                    res = max(end - begin + 1, res);
                    maxEnd = end;
                }
            }
            begin = maxEnd + 1;
        }
        return res;
    }
};

//solution two: recursive

class Solution2
{
private:
    int getLongestSubstring(string &s, int begin, int end, int k)
    {
        vector<int> count(26, 0);
        for (int i = begin; i < end; ++i)
        {
            count[s[i] - 'a']++;
        }
        int res = 0;
        for (int i = begin; i < end;)
        {
            //find the first char which appears no less than k
            while (i < end && count[s[i] - 'a'] < k)
                i++;
            if (i == end)
                break;
            int j = i;

            //find the first char which appears less than k
            while (j < end && count[s[j] - 'a'] >= k)
                j++;

            //find an substring which matches the condiation.
            if (i == begin && j == end)
                return end - begin;
            res = max(res, getLongestSubstring(s, i, j, k));
            i = j + 1;
        }
        return res;
    }

public:
    int longestSubstring(string s, int k)
    {
        if (s.size() < k)
            return 0;
        return getLongestSubstring(s, 0, s.size(), k);
    }
};

int main()
{
    system("pause");
    return 0;
}