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
    bool check(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr || node2 == nullptr)
            return node2 == nullptr && node1 == nullptr;
        if (node1->val == node2->val)
            return check(node1->left, node2->right) && check(node1->right, node2->left);
        return false;
    }

  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return check(root->left, root->right);
    }
};
int main()
{
    system("pause");
    return 0;
}