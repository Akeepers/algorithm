#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        int n = haystack.size(), m = needle.size();
        int j = 0;
        int pos = 0;
        for (int i = 0; i <= n-m; ++i)
        {
            pos = i;
            while (haystack[i] == needle[j] && i < n && j < m)
            {
                if (j == m - 1)
                    return i - j;
                i++;
                j++;
            }
            i = pos;
            j = 0;
        }
        return -1;
    }
};
int main()
{
    Solution solution;
    solution.strStr("mississippi", "issip");
    system("pause");
    return 0;
}