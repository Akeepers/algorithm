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
        vector<int> flags(points.size(), false);
        for (int i = 0; i < points.size(); ++i)
        {
            auto cur = points[i];
            int count = 0;
            map<double, int> m;
            int temp = 0;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j)
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
            if (ret > points.size() / 2)
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