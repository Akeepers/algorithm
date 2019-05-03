#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void visit(int i, int j, const int &m, const int &n, int &count)
    {
        if (i < 1 || j < 1 || i > m || j > n)
            return;
        if (i == m && j == n)
        {
            count++;
            return;
        }
        visit(i + 1, j, m, n, count);
        visit(i, j + 1, m, n, count);
    }

public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
            return 0;
        int count = 0;
        visit(1, 1, m, n, count);
        return count;
    }
};

int main()
{
    system("pause");
    return 0;
}