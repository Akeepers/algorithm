/*
 * @Author: yangpan
 * @Date: 2020-02-17 12:53:56
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-17 12:59:40
 * @Description: file content
 * @FilePath: \leetcode\1351.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

class Solution {
    void get_max(const vector<int>& vec, long long& m, long long& sum,
                 long long& pos) {
        sum = 0;
        m = 0;
        for (int i = 0; i < vec.size(); ++i) {
            sum += vec[i];
            if (vec[i] > m) {
                m = vec[i];
                pos = i;
            }
        }
    }

   public:
    bool isPossible(vector<int>& target) {
        vector<int> copy(target);
        long long count_of_one = 0, m = 0, sum = 0, pos = 0;
        for (auto item : copy) {
            count_of_one += item == 1 ? 1 : 0;
        }
        while (count_of_one < copy.size()) {
            get_max(copy, m, sum, pos);
            long long other = sum - m;
            long long sub = m - other;
            if (sub == 1) {
                count_of_one++;
                copy[pos] = sub;
            } else if (sub <= 0) {
                return false;
            } else {
                copy[pos] = sub;
            }
        }
        return true;
    }
};

int main() {
    system("pause");
    return 0;
}