#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

double cal(int n, int k, vector<long long> &values)
{
    sort(values.begin(), values.end());
    vector<double> dp(k + 1, 0);
    vector<long long> sum(n + 1, 0);
    sum[0] = values[0];
    for (int i = n - 1; i >= 0; --i)
    {
        sum[i] = sum[i + 1] + values[i];
    }
    dp[0] = sum[0] / (double)n;
    if (k == 0)
        return dp[0];
    for (int i = 1; i <= k; ++i)
    {
        int pos = distance(values.begin(), upper_bound(values.begin(), values.end(), dp[i - 1]));
        dp[i] = (pos * dp[i - 1] + sum[pos]) / (double)n;
    }
    return dp[k];
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> values(n, 0);
        for (int j = 0; j < n;)
            cin >> values[j++];

        auto ret = cal(n, k, values);
        cout << "Case #" << i << ": " << setiosflags(ios::fixed) << setprecision(6) << ret << endl;
    }
    return 0;
}