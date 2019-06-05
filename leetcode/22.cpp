#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void buildStr(vector<string> &res, string str, int leftParenthesisCount, int rightParenthesisCount)
    {
        if (leftParenthesisCount > rightParenthesisCount)
            return;
        if (leftParenthesisCount == 0 && rightParenthesisCount == 0)
        {
            res.push_back(str);
            return;
        }
        if (leftParenthesisCount > 0)
            buildStr(res, str + "(", leftParenthesisCount - 1, rightParenthesisCount);
        if (rightParenthesisCount > 0)
            buildStr(res, str + ")", leftParenthesisCount, rightParenthesisCount - 1);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n <= 0)
            return res;
        buildStr(res, "", n, n);
        return res;
    }
};
int main()
{
    system("pause");
    return 0;
}