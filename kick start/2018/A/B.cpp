#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

double cal(int n, int k, vector<int> &values)
{
    sort(values.begin(), values.end());
    long long sum = 0;
    for (auto value : values)
        sum += value;
    if (k == 0)
        return sum / (double)n;
    double res = 0.0;
    res += values.back() / (double)n;
    res += (n - 1) / (double)n / (double)n * sum;
    return res;
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