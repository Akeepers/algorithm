#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

double cal(int n, int k, vector<int> &values)
{
    sort(values.begin(), values.end());
    vector<double> dp(k+1, 0);
    long long sum = 0;
    for (auto value : values)
        sum += value;
    dp[0] = sum / (double)n;
    if (k == 0)
        return dp[0];
    double cur = 0;
    for (int i = 1; i <= n;++i){
        upper_bound(values.begin(),values.end(),dp[i-1])
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
        vector<int> values(n, 0);
        for (int j = 0; j < n;)
            cin >> values[j++];

        auto ret = cal(n,k,values);
        cout<< "Case #" << i << ": " << ret << endl;
    }
    return 0;
}