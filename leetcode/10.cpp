#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  private:
  public:
    bool isMatch(string s, string p)
    {
       int m = s.size(), n = p.size();
        vector<vector<bool>> opt(m + 1, vector<bool>(n + 1, false));
        opt[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    opt[i][j] = opt[i][j - 2] || (i && opt[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    opt[i][j] = i && opt[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return opt[m][n];
    }
};
int main()
{
    system("pause");
    return 0;
}
