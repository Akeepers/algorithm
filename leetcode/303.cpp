#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
private:
    vector<int> sums;

public:
    NumArray(vector<int> &nums)
    {
        sums.emplace_back(0);
        int res = 0;
        for (auto num : nums)
        {
            res += num;
            sums.emplace_back(res);
        }
    }

    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }
};

int main()
{
    system("pause");
    return 0;
}