#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int maxEnergy(vector<array<int, 3>> &inputs)
{
    sort(inputs.begin(), inputs.end(), [](const array<int, 3> &a, const array<int, 3> &b) -> bool { return b[0] * a[2] > a[0] * b[2]; });
    int n = inputs.size();
    int totalTime = 0;
    for (auto stone : inputs)
    {
        totalTime += stone[0];
    }
    vector<vector<int>> dp(n+1, vector<int>(totalTime+1, 0));
    for (int i = 1; i <= n; ++i)
    {
        auto stone = inputs[i - 1];
        for (int j = 1; j <= totalTime; ++j)
        {
            if (stone[0] > j)
                continue;
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stone[0]] + stone[1] - stone[2] * j);
        }
    }
    return dp[n][totalTime];
    
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n;
        vector<array<int, 3>> inputs;
        cin >> n;
        while (n--)
        {
            array<int, 3> temp;
            cin >> temp[0] >> temp[1] >> temp[2];
            inputs.push_back(temp);
        }
        int ret = maxEnergy(inputs);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}