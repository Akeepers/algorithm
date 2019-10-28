#include <iostream>
#include <vector>

using namespace std;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

class Solution
{
    bool check(int m, int n, int i, int j)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    bool dfs(vector<vector<char>> &board, string &word, int pos, int x, int y)
    {
        int m = board.size(), n = board[0].size();
        if (word[pos] != board[x][y])
            return false;
        if (pos == word.size() - 1)
            return true;
        auto tmp = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (check(m, n, x1, y1))
                if (dfs(board, word, pos + 1, x1, y1))
                    return true;
        }
        board[x][y] = tmp;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    system("pause");
    return 0;
}
