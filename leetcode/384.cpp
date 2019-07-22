#include <algorithm>
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Solution1
{
private:
    vector<int> _originalNums;
    vector<int> _curNums;
    int _size;

public:
    Solution(vector<int> &nums)
    {
        _originalNums = nums;
        _curNums = nums;
        _size = nums.size();
        srand((unsigned)time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        _curNums = _originalNums;
        return _curNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int pos = 0;
        for (int i = _size-1; i >0; --i)
        {
            pos =  rand() % (i+1);
            swap(_curNums[i], _curNums[pos]);
        }
        return _curNums;
    }
};

class Solution2
{
private:
    vector<int> _originalNums;
    vector<int> _curNums;
    int _size;

public:
    Solution(vector<int> &nums)
    {
        _originalNums = nums;
        _curNums = nums;
        _size = nums.size();
        srand((unsigned)time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        _curNums = _originalNums;
        return _curNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int pos = 0,k=_size;
        vector<int> res(_size, 0);
        for (int i = 0; i <_size; ++i)
        {
            pos =  rand() % (k--);
            res[i]= _curNums[pos];
            _curNums.erase(_curNums.begin() + pos);
        }
        _curNums = res;
        return _curNums;
    }
};


class Solution3
{
private:
    vector<int> _originalNums;
    vector<int> _curNums;
    int _size;

public:
    Solution(vector<int> &nums)
    {
        _originalNums = nums;
        _curNums = nums;
        _size = nums.size();
        srand((unsigned)time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        _curNums = _originalNums;
        return _curNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int pos = 0;
        vector<int> res(_curNums);
        for (int i = 0; i <_size; ++i)
        {
            pos =  rand() % (i+1);
            swap(res[i], res[pos]);
        }
        _curNums = res;
        return _curNums;
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