#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (numRows < 1)
            return res;
        for (int i = 0; i < numRows; ++i)
            res.emplace_back(vector<int>(i + 1, 1));
        if (numRows == 1)
            return res;
        for (int i = 1; i < numRows - 1; ++i)
            for (int j = 1; j <= i; ++j)
                res[i + 1][j] = res[i][j - 1] + res[i][j];
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}