#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sums[i + 1][j + 1] = matrix[i][j] + sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }

private:
    vector<vector<int>> sums;
};

int main()
{
    system("pause");
    return 0;
}