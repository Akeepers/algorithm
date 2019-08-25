#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// merge sort
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> indexs(n, 0);
        iota(indexs.begin(), indexs.end(), 0);
        vector<int> results(n, 0);
        mergeSort(nums, 0, n - 1, indexs, results);
        return results;
    }

private:
    void mergeSort(vector<int> &nums, int start, int end, vector<int> &indexs, vector<int> &results)
    {
        if (end - start >= 1)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid, indexs, results);
            mergeSort(nums, mid + 1, end, indexs, results);
            int i = start, j = mid + 1, pos = start;
            vector<int> tmp;
            int cnt = 0;
            while (i <= mid && j <= end)
            {
                if (nums[indexs[j]] < nums[indexs[i]])
                {
                    tmp.emplace_back(indexs[j++]);
                    cnt++;
                }
                else
                {
                    results[indexs[i]] += cnt;
                    tmp.emplace_back(indexs[i++]);
                }
            }

            while (i <= mid)
            {
                results[indexs[i]] += cnt;
                tmp.emplace_back(indexs[i++]);
            }
            while (j <= mid)
                tmp.emplace_back(indexs[j++]);
            for (auto item : tmp)
            {
                indexs[pos++] = item;
            }
        }
    }
};

//binary serach tree
class Solution1
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> results(n, 0);
        if (n <= 1)
            return results;
        Node *root = new Node(nums[n - 1]);
        for (int i = n - 2; i >= 0; --i)
            results[i] = insert(root, nums[i]);
        return results;
    }
private:
    struct Node
    {
        int val;
        int count;
        int leftSize;
        Node *left;
        Node *right;

        Node(int _val)
        {
            val = _val;
            count = 1;
            leftSize = 0;
            left = nullptr;
            right = nullptr;
        }
    };

    int insert(Node *node, int val)
    {
        if (node->val > val)
        {
            node->leftSize++;
            if (node->left == nullptr)
            {
                node->left = new Node(val);
                return 0;
            }
            else
                return insert(node->left, val);
        }
        else if (node->val < val)
        {
            if (node->right == nullptr)
            {
                node->right = new Node(val);
                return node->count + node->leftSize;
            }
            else
                return node->count + node->leftSize + insert(node->right, val);
        }
        else
        {
            node->count++;
            return node->leftSize;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {5, 2, 6, 1};
    solution.countSmaller(nums);
    system("pause");
    return 0;
}