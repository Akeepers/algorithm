#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void serachAround(vector<vector<char>> &board, int i, int j)
    {
        int m = board.size();
        int n = board.front().size();

        if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
        {
            board[i][j] = '$';
            serachAround(board, i + 1, j);
            serachAround(board, i - 1, j);
            serachAround(board, i, j + 1);
            serachAround(board, i, j - 1);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        if (m <= 1 || n <= 1)
            return;
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                serachAround(board, i, 0);
            if (board[i][n - 1] == 'O')
                serachAround(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                serachAround(board, 0, j);
            if (board[m - 1][j] == 'O')
                serachAround(board, m - 1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> inputs = {{'O', 'O'}, {'O', 'O'}};
    solution.solve(inputs);
    system("pause");
    return 0;
}