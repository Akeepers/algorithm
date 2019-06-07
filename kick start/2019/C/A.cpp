#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<unordered_map<int, int>> rowsStart, rowsEnd, colsStart, colsEnd;

void insert(int x, int y)
{
    bool l = rowsEnd[x].count(y - 1), r = rowsStart[x].count(y + 1);
    if (l && r)
    {
        int ls = rowsEnd[x][y - 1], re = rowsStart[x][y + 1];
        rowsStart[x][ls] = re, rowsEnd[x][re] = ls;
    }
    else if (l)
    {
        int ls = rowsEnd[x][y - 1];
        rowsStart[x][ls] = y, rowsEnd[x][y] = ls;
    }
    else if (r)
    {
        int re = rowsStart[x][y + 1];
        rowsEnd[x][re] = y, rowsStart[x][y] = re;
    }
    else
    {
        rowsEnd[x][y] = rowsStart[x][y] = y;
    }

    l = colsEnd[y].count(x - 1), r = colsStart[y].count(x + 1);
    if (l && r)
    {
        int ls = colsEnd[y][x - 1], re = colsStart[y][x + 1];
        colsStart[y][ls] = re, colsEnd[y][re] = ls;
    }
    else if (l)
    {
        int ls = colsEnd[y][x - 1];
        colsStart[y][ls] = x, colsEnd[y][x] = ls;
    }
    else if (r)
    {
        int re = colsStart[y][x + 1];
        colsEnd[y][re] = x, colsStart[y][x] = re;
    }
    else
    {
        colsEnd[y][x] = colsStart[y][x] = x;
    }
}

pair<int, int> calLocation(int m, int n, int x, int y, const string &instructions)
{
    rowsStart.clear();
    rowsEnd.clear();
    colsStart.clear();
    colsEnd.clear();
    rowsStart.resize(m + 1);
    rowsEnd.resize(m + 1);
    colsStart.resize(n + 1);
    colsEnd.resize(n + 1);

    rowsStart[x][y] = y;
    rowsEnd[x][y] = y;
    colsStart[y][x] = x;
    colsEnd[y][x] = x;

    for (auto item : instructions)
    {
        switch (item)
        {
        case 'E':
            if (rowsStart[x].count(y + 1))
                y = rowsStart[x][y + 1] + 1;
            else
                y++;
            break;
        case 'W':
            if (rowsEnd[x].count(y - 1))
                y = rowsEnd[x][y - 1] - 1;
            else
                y--;
            break;
        case 'S':
            if (colsStart[y].count(x + 1))
                x = colsStart[y][x + 1] + 1;
            else
                x++;
            break;
        case 'N':
            if (colsEnd[y].count(x - 1))
                x = colsEnd[y][x - 1] - 1;
            else
                x--;
            break;
        }
        insert(x, y);
    }
    return make_pair(x, y);
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, r, c, s_r, s_c;
        string instructions;
        cin >> n >> r >> c >> s_r >> s_c >> instructions;

        auto ret = calLocation(r, c, s_r, s_c, instructions);
        cout << "Case #" << i << ": " << ret.first << "  " << ret.second << endl;
    }
    return 0;
}