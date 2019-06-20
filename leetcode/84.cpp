#include <iostream>
#include <stack>
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
        heights.emplace_back(-1);
        int n = heights.size();
        int maxArea = 0, i = 0;
        stack<int> indexs;
        while (i < n)
        {
            if (indexs.empty() || heights[i] >= heights[indexs.top()])
                indexs.push(i++);
            else
            {
                int j = indexs.top();
                indexs.pop();
                int cur = heights[j] * (indexs.empty() ? i : (i - indexs.top() - 1));
                maxArea = max(maxArea, cur);
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<int> input = {4, 2, 0, 3, 2, 5};
    Solution solution;
    solution.largestRectangleArea(input);
    system("pause");
    return 0;
}