#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void slove()
{
    int n, p, score;
    cin >> n >> p;
    vector<int> scores(n + 1, 0);
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());
    for (int i = 1; i <= n; ++i)
    {
        sum[i] += sum[i - 1] + scores[i];
    }

    int res = INT_MAX;
    for (int i = p; i <= n; ++i)
    {
        int max = scores[i];
        int cur = p * max - (sum[i] - sum[i - p]);
        res = min(cur, res);
    }
    cout << res << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {

        cout << "Case #" << i << ": ";
        slove();
    }
    return 0;
}
