#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
    static unordered_map<char, vector<char>> mapping;
    void visit(string &digits, int pos, string cur, vector<string> &res)
    {
        if (pos == digits.size())
        {
            res.emplace_back(cur);
            return;
        }
        if (digits[pos] - '9' > 0 || digits[pos] - '2' < 0)
            return;
        for (auto item : mapping[digits[pos]])
        {
            visit(digits, pos + 1, cur + item, res);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        visit(digits, 0, "", res);
        return res;
    }
};
unordered_map<char, string> Solution::mapping = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl", {'6', "mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9',"wxyz"}};

int main()
{
    system("pause");
    return 0;
}