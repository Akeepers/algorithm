#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        auto result = log10(n) / log10(3);      
        return floor(result)==result;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPowerOfThree(19684) << endl;
    system("pause");
    return 0;
}