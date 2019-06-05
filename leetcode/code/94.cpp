#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        auto node=root;
        while(node!=nullptr||!s.empty()){
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
            if(!s.empty()){
                node=s.top();
                res.emplace_back(node->val);
                s.pop();
                node=node->right;
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