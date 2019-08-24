#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
    void inOrder(TreeNode *node, vector<int> &res)
    {
        if (node == nullptr)
            return;
        inOrder(node->left, res);
        res.emplace_back(node->val);
        inOrder(node->right, res);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        vector<int> res;
        inOrder(root, res);
        for (int i = 1; i < res.size(); ++i)
        {
            if (res[i] <= res[i - 1])
                return false;
        }
        return true;
    }
};

class Solution1
{
    bool inOrder(TreeNode *node, TreeNode *pre)
    {
        if (node == nullptr)
            return true;
        if (pre != nullptr && pre->val >= node->val)
            return false;
        return inOrder(node->left, node)&&inOrder(node->right, node);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        return inOrder(root, pre);
    }
};

int main()
{
    system("pause");
    return 0;
}