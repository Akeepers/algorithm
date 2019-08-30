#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> items;
        for(auto building:buildings){
            items.emplace_back(building[0], -building[2]);
            items.emplace_back(building[1], building[2]);
        }
        sort(items.begin(), items.end());
        return results;
    }
};

int main()
{
    system("pause");
    return 0;
}