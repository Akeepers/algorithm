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
    TreeNode *createNode(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        if (left == right)
            return new TreeNode(nums[mid]);

        TreeNode *node = new TreeNode(nums[mid]);

        node->left = createNode(nums, left, mid - 1);
        node->right = createNode(nums, mid + 1, right);
        return node;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        auto root = createNode(nums, 0, nums.size() - 1);
        return root;
    }
};

int main()
{
    system("pause");
    return 0;
}