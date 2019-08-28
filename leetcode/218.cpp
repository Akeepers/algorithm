#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> height(INT_MAX+1, 0);
        int end = 0;
        for (auto building : buildings)
        {
            for (int i = building[0]; i <= building[1];++i){
                height[i] = height[i] < building[2] ? building[2] : height[i];
                end = building[1] > end ? building[1] : end;
            }
        }
        int last = 0;
        vector<vector<int>> results;
        for (int i = 0; i <= end; ++i)
        {
            if(height[i]!=last){
                vector<int> tmp = {i, height[i]};
                results.emplace_back(tmp);
                last = height[i];
            }
        }
        vector<int> tmp = {end, 0};
        results.emplace_back(tmp);
        return results;
    }
};

int main()
{
    system("pause");
    return 0;
}