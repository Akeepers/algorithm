#include <iostream>

using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int result = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            switch (s[i])
            {
            case 'I':
                result += 1;
                break;
            case 'V':
                if (i > 0 && s[i - 1] == 'I')
                {
                    result += 4;
                    i--;
                }
                else
                    result += 5;
                break;
            case 'X':
                if (i > 0 && s[i - 1] == 'I')
                {
                    result += 9;
                    i--;
                }
                else
                    result += 10;
                break;
            case 'L':
                if (i > 0 && s[i - 1] == 'X')
                {
                    result += 40;
                    i--;
                }
                else
                    result += 50;
                break;
            case 'C':
                if (i > 0 && s[i - 1] == 'X')
                {
                    result += 90;
                    i--;
                }
                else
                    result += 100;
                break;
            case 'D':
                if (i > 0 && s[i - 1] == 'C')
                {
                    result += 400;
                    i--;
                }
                else
                    result += 500;
                break;
            case 'M':
                if (i > 0 && s[i - 1] == 'C')
                {
                    result += 900;
                    i--;
                }
                else
                    result += 1000;
                break;
            default:
                result += 0;
                break;
            }
        }
        return result;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution solution;
    cout<<solution.romanToInt(s)<<endl;
    system("pause");
    return 0;
}
