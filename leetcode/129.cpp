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
    void visit(TreeNode *node, int &sum, int cur)
    {
        if (node == nullptr)
            return;
        cur = cur * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
            sum += cur;
        visit(node->left, sum, cur);
        visit(node->right, sum, cur);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        visit(root, sum, 0);
        return sum;
    }
};
int main()
{
    system("pause");
    return 0;
}