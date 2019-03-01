#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    double getKth(vector<int> &nums1, int start1, int size1, vector<int> &nums2, int start2, int size2, int k)
    {
        //assume size1>=size2
        if (size2 > size1)
            return getKth(nums2, start2, size2, nums1, start1, size1, k);
        if (size2 == 0)
            return nums1[k - 1 + start1];
        if (k == 1)
            return nums1[start1] > nums2[start2] ? nums2[start2] : nums1[start1];
        int posOfNums2 = k / 2 > size2 ? size2 : k / 2;
        int posOfNums1 = k - posOfNums2;
        if (nums2[posOfNums2 + start2 - 1] < nums1[posOfNums1 + start1 - 1])
            return getKth(nums1, start1, size1, nums2, posOfNums2 + start2, size2 - posOfNums2, k - posOfNums2);
        if (nums2[posOfNums2 + start2 - 1] == nums1[posOfNums1 + start1 - 1])
            return nums2[posOfNums2 + start2 - 1];
        return getKth(nums1, posOfNums1 + start1, size1 - posOfNums1, nums2, start2, size2, k - posOfNums1);
    }

  public:
    double
    findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n) / 2;
        if ((m + n) % 2 == 0)
            return (getKth(nums1, 0, m, nums2, 0, n, k)+getKth(nums1, 0, m, nums2, 0, n, k + 1)) / 2.0;
        else
            return getKth(nums1, 0, m, nums2, 0, n, k + 1);
    }
};

int main()
{
    Solution solution;
    vector<int> vec1 = {1, 4};
    vector<int> vec2 = {2, 3, 5, 6};
    cout << solution.findMedianSortedArrays(vec1, vec2) << endl;
    system("pause");
}