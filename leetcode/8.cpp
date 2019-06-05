#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        int sign = 1;
        long long result = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            auto pos = str.find_first_not_of(' ');
            if(pos==string::npos)
                return 0;
            i=pos;
            if (str[i] == '-' || str[i] == '+')
                sign = str[i++] == '-' ? -1 : 1;
            while (i < str.size() && '0' <= str[i] && str[i] <= '9')
            {
                result = result * 10 + str[i++] - '0';
                if (result * sign > INT_MAX)
                    return INT_MAX;
                if (result * sign < INT_MIN)
                    return INT_MIN;
            }
            break;
        }
        return result * sign;
    }
};

int main()
{
    string str = "20000000000000000000";
    Solution solution;
    cout << solution.myAtoi(str) << endl;
    system("pause");
    return 0;
}