#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int firstUniqChar(string s)
    {
        int list[256] = {0};
        for (auto i : s)
            list[i]++;
        for (int i = 0; i < s.length(); i++)
            if (list[s[i]] == 1)
                return i;
        return -1;
    }
};
int main()
{
    system("pause");
    return 0;
}
