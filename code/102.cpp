#include <iostream>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        vector<int> vec;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {

            auto cur = q.front();
            q.pop();
            if (cur == nullptr)
            {
                res.emplace_back(vec);
                vec.resize(0);
                if (!q.empty())
                    q.push(nullptr);
            }
            else
            {
                vec.emplace_back(cur->val);
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}