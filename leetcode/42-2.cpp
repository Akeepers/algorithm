#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n < 3)
            return 0;
        int ret = 0;
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && height[i] > height[s.top()])
            {
                int low = height[s.top()];
                s.pop();
                if (!s.empty())
                {
                    int width = i - s.top() - 1;
                    int h = min(height[i], height[s.top()]) - low;
                    ret += (width * h);
                }
            }
            s.push(i);
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    vector<int> inputs = {5, 4, 1, 2};
    cout << solution.trap(inputs) << endl;
    system("pause");
    return 0;
}