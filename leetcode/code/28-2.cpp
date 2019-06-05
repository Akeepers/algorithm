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
        vector<int> next(needle.size(), 0);
        for (int i = 2;i<needle.size();++i){
            if(needle[0+next[i-1]==needle[i-1]])
                next[i] = next[i-1] + 1;
            else
                next[i]=
        }
    }
};
int main()
{
    Solution solution;
    solution.strStr("mississippi", "issip");
    system("pause");
    return 0;
}