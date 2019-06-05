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
    int visit(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return max(visit(node->right) + 1, visit(node->left) + 1);
    }

  public:
    int maxDepth(TreeNode *root)
    {
        return visit(root);
    }
};

int main()
{
    system("pause");
    return 0;
}