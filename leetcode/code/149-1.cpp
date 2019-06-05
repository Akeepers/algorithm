#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ret = 0;
        int n = points.size();
        if (n < 3)
            return n;
        vector<int> flags(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (flags[i])
                continue;
            auto cur = points[i];
            int count = 0;
            unordered_map<double, int> m;
            int temp = 0;
            int duplicate = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (cur[1] == points[j][1])
                {
                    if (cur[0] == points[j][0])
                    {
                        duplicate++;
                        flags[j] = true;
                        continue;
                    }
                    count++;
                }
                else
                {
                    double k = (cur[0] - points[j][0]) * 1.0 / (cur[1] - points[j][1]);
                    if (m.find(k) == m.end())
                        m.insert(pair<double, int>(k, 1));
                    else
                        m[k]++;
                    temp = max(temp, m[k]);
                }
            }
            temp = max(temp + duplicate, count + duplicate);
            ret = max(temp, ret);
            if (ret > n - i - 1)
                break;
        }
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}