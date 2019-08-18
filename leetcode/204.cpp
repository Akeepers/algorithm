#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> marked(n, true);
        int cnt = 0;
        for (int i = 2; i < n; ++i)
        {
            if (marked[i])
            {
                cnt++;
                for (int j = i + i; j < n; j += i)
                    marked[j] = false;
            }
        }
        return cnt;
    }
};

int main()
{
    system("pause");
    return 0;
}