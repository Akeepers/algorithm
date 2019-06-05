#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        while (n != 1)
        {
            if (n % 3 != 0)
                return false;
            n = n / 3;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPowerOfThree(19684) << endl;
    system("pause");
    return 0;
}