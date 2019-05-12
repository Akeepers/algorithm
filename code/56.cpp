#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> res;
        int n = intervals.size();
        if (n < 1)
            return res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
            else
            {
                res.push_back(intervals[i - 1]);
            }
        }
        res.push_back(intervals[n - 1]);
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}
