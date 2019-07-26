#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size() || s.empty() || t.empty())
            return "";
        int left = 0, right = 0, res = INT_MAX, resLeft = 0, resRight = 0;
        unordered_map<char, int> map,pattern;
        for (auto item : t)
        {
            map[item]++;
        }
        int match = map.size(),cur=0;
        for (; right < s.size();)
        {
            if (map.find(s[right]) != map.end())
            {
                pattern[s[right]]++;
                if (pattern[s[right]] == map[s[right]])
                    cur++;
            }
            if (cur == match)
            {
                while (left < right - t.size() + 2)
                {
                    if (map.find(s[left]) != map.end())
                    {
                        pattern[s[left]]--;
                        if (pattern[s[left]]<map[s[left]])
                        {
                            cur--;
                            if (res > right - left + 1)
                            {
                                res = right - left + 1;
                                resLeft = left ;
                                resRight = right;
                            }
                            left++;
                            break;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        return res == INT_MAX ? "" : s.substr(resLeft, resRight - resLeft + 1);
    }
};

int main()
{
    Solution solution;
    solution.minWindow("aa", "aa");
    system("pause");
    return 0;
}