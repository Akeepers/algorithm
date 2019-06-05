#include <iostream>

using namespace std;

class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};

int main()
{

    return 0;
}