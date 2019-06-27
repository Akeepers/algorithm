#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int dfs(TreeNode *node, int &res)
    {
        int l = node->left != nullptr ? dfs(node->left, res) : INT_MIN;
        int r = node->right != nullptr ? dfs(node->right, res) : INT_MIN;
        res = max(res, l);
        res = max(res, r);
        res = max(res, node->val);
        if (l > 0)
            res = max(res, l + node->val);
        if (r > 0)
            res = max(res, r + node->val);
        if (l != INT_MIN && r != INT_MIN && l + r > 0)
            res = max(res, l + r + node->val);
        int resL = l > 0 ? l + node->val : node->val;
        int resR = r > 0 ? r + node->val : node->val;
        return max(resL, resR);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        if (root != nullptr)
            dfs(root, res);
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}