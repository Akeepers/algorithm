#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//hash table
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> keys(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto num : nums2)
        {
            if (keys.count(num))
            {
                res.emplace_back(num);
                keys.erase(num);
            }
        }
        return res;
    }
};

//two pointer & sort
class Solution1
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                if (res.empty() || nums1[i] != res.back())
                {
                    res.emplace_back(nums1[i]);
                }
                i++;
                j++;
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