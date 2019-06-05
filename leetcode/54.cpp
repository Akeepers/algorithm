#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int m = matrix.size();
        if (m == 0)
            return res;
        int n = matrix.front().size();
        if (n == 0)
            return res;
        res.resize(m * n);
        int pos = 0;
        int beginCol = 0, endCol = n - 1;
        int beginRow = 0, endRow = m - 1;
        while (endRow >= beginRow && endCol >= beginCol)
        {

            for (int i = beginCol; i <= endCol; ++i)
                res[pos++] = matrix[beginRow][i];
            if (++beginRow > endRow)
                break;
            for (int i = beginRow; i <= endRow; ++i)
                res[pos++] = matrix[i][endCol];
            if (--endCol < beginCol)
                break;
            for (int i = endCol; i >= beginCol; --i)
                res[pos++] = matrix[endRow][i];
            if (--endRow < beginRow)
                break;
            for (int i = endRow; i >= beginRow; --i)
                res[pos++] = matrix[i][beginCol];
            if (beginCol++ > endCol)
                break;
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> inputs = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    Solution solution;
    solution.spiralOrder(inputs);
    system("pause");
    return 0;
}