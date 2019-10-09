#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

const vector<int> dx = {1, -1};
const vector<int> dy = {1, -1};

class Solution
{
{
    bool check(int i, int j, int m, int n)
    {
        return (i < m && i >= 0) && (j < n && j >= 0);
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0 && !visited[i][j])
                {
                    queue<pair<int, int>> q;
                    q.insert(make_pair(i, j));
                }
            }
        }
    }
};

int main()
{

    system("pause");
    return 0;
}