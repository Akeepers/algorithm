#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int even = 0, odd = 0;
        for (auto chip : chips)
        {
            chip & 1 ? odd++ : even++;
        }
        return min(odd, even);
    }
};

int main()
{

    system("pause");
    return 0;
}