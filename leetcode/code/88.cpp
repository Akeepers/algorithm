#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while (k >= 0)
        {
            if (j < 0)
                break;
            if (i < 0)
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};

int main()
{
    system("pause");
    return 0;
}