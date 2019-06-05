#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int posOfFirstZeroRow = -1;

        //find the row which can store 0-column
        for (int i = 0; i < m && posOfFirstZeroRow == -1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    posOfFirstZeroRow = i;
                    break;
                }
            }
        }
        if (posOfFirstZeroRow == -1)
            return;
        for (int i = posOfFirstZeroRow + 1; i < m; ++i)
        {
            bool flag = false;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    flag = true;
                    matrix[posOfFirstZeroRow][j] = 0;
                }
            }
            //set the row to 0
            if (flag)
            {
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }

        //set the value of 0-column
        for (int i = 0; i < n; ++i)
        {
            if (matrix[posOfFirstZeroRow][i] == 0)
            {
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 0; i < n; ++i)
            matrix[posOfFirstZeroRow][i] = 0;
    }
};

int main()
{
    system("pause");
    return 0;
}