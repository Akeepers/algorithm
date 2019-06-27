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
private:
    // get the longest path in current tree
    int visit(TreeNode *node, int &longest)
    {
        //get longest in left subtree
        int left = node->left != nullptr ? visit(node->left, longest) : 0;
        int right = node->right != nullptr ? visit(node->right, longest) : 0;
        int resLeft = node->left && node->left->val == node->val ? left + 1 : 0;
        int resRight = node->right && node->right->val == node->val ? right + 1 : 0;
        longest = max(longest, resLeft + resRight);
        return max(resLeft, resRight);
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = 0;
        visit(root, res);
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}