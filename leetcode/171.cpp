#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        if (s.empty())
            return 0;
        int i = 0, j = s.size() - 1;
        int res = 0;
        while (j >= 0)
            res += pow(26, i++) * (s[j--] - 'A'+1);
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}
