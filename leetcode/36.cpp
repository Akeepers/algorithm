#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> visited1(9, vector<bool>(9, false)), visited2(9, vector<bool>(9, false)), visited3(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (visited1[i][num] || visited2[j][num] || visited3[k][num])
                        return false;
                    visited1[i][num] = visited2[j][num] = visited3[k][num] = true;
                }

        return true;
    }
};

int main()
{
    system("pause");
    return 0;
}