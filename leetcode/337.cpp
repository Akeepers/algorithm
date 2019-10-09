#include <algorithm>
#include <climits>
#include <iostream>
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
    pair<int, int> dfs(TreeNode *node)
    {
        if (node == nullptr)
            return make_pair(0, 0);
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        auto i = max(l.first, l.second) + max(r.first, r.second);
        auto j = l.first + r.first + node->val;
        return make_pair(i, j);
    }

public:
    int rob(TreeNode *root)
    {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

int main()
{
    system("pause");
    return 0;
}