/*
 * @Author: yangpan
 * @Date: 2020-02-02 11:25:30
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-04 11:21:31
 * @Description: file content
 * @FilePath: \leetcode\1339.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef long long ll;

const ll m = 1e9 + 7;
class Solution {
   private:
    ll _total_sum = 0, result = 0;
    int count(TreeNode* node) {
        int sum = 0;
        if (nullptr == node) return 0;
        sum = node->val + count(node->left) + count(node->right);
        result = max(result, sum * (_total_sum - sum));
        return sum;
    }

   public:
    int maxProduct(TreeNode* root) {
        _total_sum = count(root);
        count(root);
        return result % m;
    }
};

int main() {
    vector<int> inputs = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    Solution s;
    s.maxJumps(inputs, 2);
    system("pause");
    return 0;
}