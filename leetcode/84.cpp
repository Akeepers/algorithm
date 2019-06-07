#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.empty())
            return 0;
        if (heights.size() == 1)
            return heights[0];
        int n = heights.size();
        int minHeight = heights[0];
        vector<int> dp(n, 0);
        dp[0] = heights[0];
        for (int i = 1; i < n; ++i)
        {
            
        }
    }
};

int main()
{
    system("pause");
    return 0;
}