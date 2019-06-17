#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0;
        int starI = -1, starJ = -1;
        int m = s.size(), n = p.size();
        while (i < m)
        {
            if (j >= n)
            {
                if (starJ != -1)
                {
                    j = starJ + 1;
                    i = ++starI;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (p[j] == '*')
                {
                    starJ = j++;
                    starI = i;
                }
                else if (p[j] == '?' || s[i] == p[j])
                {
                    j++;
                    i++;
                }
                else if (starJ != -1)
                {
                    i = ++starI;
                    j = starJ + 1;
                }
                else
                {
                    return false;
                }
            }
        }
        while (j < n && p[j] == '*')
        {
            j++;
        }
        return j == n;
    }
};

int main()
{
    system("pause");
    return 0;
}