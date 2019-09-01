#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

//divide and conquer
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        if (buildings.empty())
            return buildings;
        return cal(buildings, 0, buildings.size() - 1);
    }

private:
    vector<vector<int>> cal(vector<vector<int>> &buildings, int start, int end)
    {
        vector<vector<int>> res;
        if (end - start > 0)
        {
            int mid = (start + end) / 2;
            auto left = cal(buildings, start, mid);
            auto right = cal(buildings, mid + 1, end);
            int i = 0, j = 0, m = left.size(), n = right.size(), lh = 0, rh = 0;
            while (i < m && j < n)
            {
                if (left[i][0] < right[j][0])
                {
                    lh = left[i][1];
                    if (res.empty() || res.back()[1] != max(lh, rh))
                        res.emplace_back(vector<int>{left[i][0], max(lh, rh)});
                    i++;
                }
                else if (left[i][0] > right[j][0])
                {
                    rh = right[j][1];
                    if (res.empty() || res.back()[1] != max(lh, rh))
                        res.emplace_back(vector<int>{right[j][0], max(lh, rh)});
                    j++;
                }
                else
                {
                    lh = left[i][1];
                    rh = right[j][1];
                    if (res.empty() || res.back()[1] != max(lh, rh))
                        res.emplace_back(vector<int>{right[j][0], max(lh, rh)});
                    i++;
                    j++;
                }
            }
            while (i < m)
                res.emplace_back(left[i++]);
            while (j < n)
                res.emplace_back(right[j++]);
        }
        else
        {
            res.emplace_back(vector<int>{buildings[start][0], buildings[start][2]});
            res.emplace_back(vector<int>{buildings[start][1], 0});
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}