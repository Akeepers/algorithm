#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
   private:
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder,int beginPre, int endPre,int beginIn,int endIn){
        if(beginPre==endPre)
            
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
int main()
{
    system("pause");
    return 0;
}