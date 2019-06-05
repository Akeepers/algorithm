#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix.front().size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            matrix[i][j] > target ? j-- : i++;
        }
        return false;
    }
};
int main()
{
    system("pause");
    return 0;
}