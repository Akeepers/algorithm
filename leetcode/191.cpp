#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; ++i)
        {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }
};

class Solution2
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
int main()
{

    system("pause");
    return 0;
}