#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> _originalNums;
    vector<int> _curNums;

public:
    Solution(vector<int> &nums)
    {
        _originalNums = nums;
        _curNums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main()
{
    system("pause");
    return 0;
}