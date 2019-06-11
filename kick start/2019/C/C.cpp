#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int cal(const vector<int> &positions, const vector<int> &colors, int n, int k)
{
    unordered_map<int, vector<int>> dogs;
    unordered_map<int, int> colorNo;
    int no = 1;
    for (int i = 0; i < n; ++i)
    {
        if (colorNo.count(colors[i]) == 0)
            colorNo[colors[i]] = no++;
    }
    for (int i = 0; i < n; ++i)
    {
        dogs[colorNo[colors[i]]].emplace_back(positions[i]);
    }
    int c = dogs.size();
    for (int i = 0; i < c; ++i)
    {
        sort(dogs[i].begin(), dogs[i].end());
    }
    vector<vector<vector<int>>> dp(c + 1, vector<vector<int>>(n + 1, vector<int>(2, INT_MAX)));
    for (int i = 0; i <= c; ++i)
    {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }
    for (int i = 1; i <= dogs[1].size(); ++i)
    {
        dp[1][i][0] = 2 * dogs[1][i - 1];
        dp[1][i][1] = dogs[1][i - 1];
    }
    if (c == 1)
        return dp[c][k][1];
    for (int i = 2; i <= c; ++i)
    {
        for (int j = 1; j <= dogs[i].size(); ++j)
        {
            for (int m = 0; m <= j && m <= dogs[i - 1].size(); ++m)
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - m][0] + dogs[i][j - m - 1] * 2);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - m][1] + dogs[i][j - m - 1] * 2);
                dp[i][j][1] = min(dp[i][j][0], dp[i - 1][j - m][1] + dogs[i][j - m - 1]);
            }
        }
    }
    return dp[c][k][1];
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, k, c = 0;
        cin >> n >> k;
        vector<int> positions(n, 0), colors(n, 0);
        for (int j = 0; j < n; ++j)
        {
            cin >> positions[j];
        }
        for (int j = 0; j < n; ++j)
        {
            cin >> colors[j];
        }
        cout << "Case #" << i << ": " << cal(positions, colors, n, k) << endl;
    }
    return 0;
}