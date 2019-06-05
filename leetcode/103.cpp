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
    void visit(stack<TreeNode *> s, vector<vector<int>> &ret, bool &flag)
    {
        vector<int> vec;
        stack<TreeNode *> stack;
        while (!s.empty())
        {
            vec.emplace_back(s.top()->val);
            if (flag)
            {
                if (s.top()->left != nullptr)
                    stack.push(s.top()->left);
                if (s.top()->right != nullptr)
                    stack.push(s.top()->right);
            }
            else
            {
                if (s.top()->right != nullptr)
                    stack.push(s.top()->right);
                if (s.top()->left != nullptr)
                    stack.push(s.top()->left);
            }
            s.pop();
        }
        flag = !flag;
        ret.emplace_back(vec);
        if (!stack.empty())
            visit(stack, ret, flag);
    }

  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if(root==nullptr)
            return ret;
        stack<TreeNode *> stack;
        stack.push(root);
        bool flag = true;
        visit(stack, ret, flag);
        return ret;
    }
};
int main()
{
    system("pause");
    return 0;
}