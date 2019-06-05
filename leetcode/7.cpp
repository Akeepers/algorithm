#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        long result = 0;
        while (x!= 0)
        {
            result *= 10;
            result += x % 10;
            x = x / 10;
        }
        if (result > INT32_MAX || result < INT32_MIN)
            return 0;
        return result;
    }
};

int main()
{
    Solution solution;
    solution.reverse(123);
    system("pause");
    return 0;
}