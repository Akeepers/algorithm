#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<pair<int, int>> rowU(int n, const vector<int> &row)
{
    int start = 0;
    int i = 0;
    vector<pair<int, int>> res;
    while (i < n)
    {
        if (row[i] == row[start])
            i++;
        else
        {
            if (i != start)
                res.emplace_back(pair<int, int>(i - 1, start));
            start = i;
        }
    }
    if (i != start)
        res.emplace_back(pair<int, int>(i - 1, start));
    return res;
}
int cal(int m, int n, const vector<vector<int>> &inputs, int k)
{
    int max = m;
    unordered_map<int, unordered_set<int>> last;
    for (int i = 0; i < m; ++i)
    {
        auto row = inputs[i];
        auto pairs = rowU(n, row);
        if (pairs.empty())
            continue;
        unordered_map<int, unordered_set<int>> curRow;
        for (auto pair : pairs)
        {
            curRow[pair.first].insert(pair.second);
            if (last.find(pair.first) != last.end() && last[pair.first].find(pair.second) != last[pair.first].end())
                continue;
            int cur = pair.first - pair.second + 1;
            int k = i + 1;
            while (k < m)
            {
                bool flag = false;
                int num = inputs[k][pair.second];
                for (int j = pair.second + 1; j <= pair.first; ++j)
                {
                    if (num != inputs[k][j])
                    {
                        flag = true;
                        break;
                    }
                }
                k++;
                if (!flag)
                    cur += pair.first - pair.second + 1;
                else
                    break;
            }
            if (cur > max)
                max = cur;
        }
        last = curRow;
    }
    return max;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int r, c, k;
        cin >> r >> c >> k;
        vector<vector<int>> inputs(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> inputs[i][j];
            }
        }
        auto ret = cal(r, c, inputs, k);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}