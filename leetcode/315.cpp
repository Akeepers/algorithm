#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mapping(n, 0);
        for (int i = 0; i < n; ++i)
            mapping[i] = i;
        vector<int> results(n, 0);
    }

private:
    void mergeSort(vector<int> &nums, int start, int end, vector<int> &indexs, vector<int> &results)
    {
        if (end - start > 1)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid, indexs, results);
            mergeSort(nums, mid + 1, end, indexs, results);
            int i = start, j = mid + 1, pos = start;
            vector<int> tmp;
            while (i <= mid && j <= end)
            {
                if (nums[indexs[j]] < nums[indexs[i]])
                {
                    tmp.emplace_back(indexs[j++]);
                    // indexs[pos++] = indexs[j++];
                }
                else
                {
                    // indexs[pos++] = indexs[i++];
                    tmp.emplace_back(indexs[i++]);
                }
            }
            for (auto item : tmp)
            {
                indexs[pos++] = item;
            }
            while (i <= mid)
            {
                indexs[pos++] = indexs[i++];
            }
            while (j <= mid)
            {
                indexs[pos++] = indexs[j++];
            }
        }
    }
};
int main()
{
    system("pause");
    return 0;
}