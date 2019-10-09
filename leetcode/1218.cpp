#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {

        unordered_map<int, int> forwards;
        int res = 0;
        for (auto item : arr)
        {
            if (forwards.count(item - difference))
            {
                forwards[item] = forwards[item - difference] + 1;
                res = max(res, forwards[item]);
            }
            else
            {
                forwards[item] = 1;
            }
        }
        return res == 0 ? 1 : res;
    }
};

int main()
{
    system("pause");
    return 0;
}