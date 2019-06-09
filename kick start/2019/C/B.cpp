#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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

int cal(int m, int n, const vector<vector<int>> &inputs, int k)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int pos = i;
            int curMin = inputs[j][pos], curMax = inputs[j][pos];
            pos++;
            while (pos < n)
            {
                if (inputs[j][pos] > curMax)
                    curMax = inputs[j][pos];
                else if (inputs[j][pos] < curMin)
                    curMin = inputs[j][pos];
                
            }
        }
    }
    return max;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int r, c, k;
        cin >> r >> c >> k;
        vector<vector<int>> inputs(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> inputs[i][j];
            }
        }
        auto ret = cal(r, c, inputs, k);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}