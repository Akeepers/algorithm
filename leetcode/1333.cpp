/*
 * @Author: yangpan
 * @Date: 2020-01-27 10:16:29
 * @LastEditors: yangpan
 * @LastEditTime: 2020-01-31 16:29:50
 * @Description: file content
 * @FilePath: \leetcode\1333.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
bool mycompare(const vector<int> &a, const vector<int> &b) {
    if (a[1] != b[1]) {
        return a[1] > b[1];
    } else {
        return a[0] > b[0];
    }
}

class Solution {
   public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                  int veganFriendly, int maxPrice,
                                  int maxDistance) {
        vector<vector<int>> temp;
        for (auto restaurant : restaurants) {
            if (veganFriendly == 0 || veganFriendly == restaurant[2]) {
                if (restaurant[3] <= maxPrice && restaurant[4] <= maxDistance) {
                    temp.push_back(restaurant);
                }
            }
        }
        sort(temp.begin(), temp.end(), mycompare);
        vector<int> res;
        for (auto item : temp) {
            res.push_back(item[0]);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}