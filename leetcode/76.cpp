#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         if (t.size() > s.size() || s.empty() || t.empty())
//             return "";
//         int left = 0, right = 0, res = INT_MAX, resLeft = 0, resRight = 0;
//         unordered_map<char, int> strs, pattern;
//         for (auto item : t)
//         {
//             strs[item]++;
//         }
//         int match = strs.size(), cur = 0;
//         for (; right < s.size();)
//         {
//             if (strs.find(s[right]) != strs.end())
//             {
//                 pattern[s[right]]++;
//                 if (pattern[s[right]] == strs[s[right]])
//                     cur++;
//             }
//             if (cur == match)
//             {
//                 while (left < right - t.size() + 2)
//                 {
//                     if (strs.find(s[left]) != strs.end())
//                     {
//                         pattern[s[left]]--;
//                         if (pattern[s[left]] < strs[s[left]])
//                         {
//                             cur--;
//                             if (res > right - left + 1)
//                             {
//                                 res = right - left + 1;
//                                 resLeft = left;
//                                 resRight = right;
//                             }
//                             left++;
//                             break;
//                         }
//                     }
//                     left++;
//                 }
//             }
//             right++;
//         }
//         return res == INT_MAX ? "" : s.substr(resLeft, resRight - resLeft + 1);
//     }
// };

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size() || s.empty() || t.empty())
            return "";
        int left = 0, right = 0, res = INT_MAX, resLeft = 0;
        vector<int> pattern(128, 0);
        int required = t.size();
        for (int i = 0; i < t.size();++i)
        {
            pattern[t[i]]++;
        }
        while(right <= s.size())
        {
            if (required > 0)
            {
                pattern[s[right]]--;
                if (pattern[s[right]] >= 0)
                    required--;
                right++;
            }
            else
            {
                if (res > right - left )
                {
                    res = right - left ;
                    resLeft = left;
                }
                pattern[s[left]]++;
                if (pattern[s[left]] > 0)
                    required++;
                left++;
            }
        }
        return res == INT_MAX ? "" : s.substr(resLeft, res);
    }
};

int main()
{
    Solution solution;
    solution.minWindow("ADOBECODEBANC",
"ABC");
    system("pause");
    return 0;
}