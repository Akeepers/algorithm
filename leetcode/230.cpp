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
    int visit(TreeNode *node, int &k)
    {
        if (node == nullptr)
            return 0;
        int val = visit(node->left, k);
        if (k == 0)
            return val;
        k--;
        if (k == 0)
            return node->val;
        return visit(node->right, k);
    }

  public:
    int kthSmallest(TreeNode *root, int k)
    {
        int val = visit(root, k);
        return val;
    }
};

int main()
{
    system("pause");
    return 0;
}