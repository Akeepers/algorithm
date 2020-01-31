/*
 * @Author: yangpan
 * @Date: 2020-01-31 15:43:15
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-01-31 16:05:04
 * @Description: file content
 * @FilePath: \leetcode\1297.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length(), cnt = 0;
        if (n < minSize) {
            return 0;
        }
        unordered_map<string, int> counts;
        vector<int> chars(26, 0);
        for (int i = 0; i < minSize; ++i) {
            int tmp = s[i] - 'a';
            chars[tmp]++;
            if (chars[tmp] == 1) cnt++;
        }
        if (cnt <= maxLetters) {
            counts[s.substr(0, minSize)]++;
        }
        for (int i = minSize; i < n; ++i) {
            int tmp = s[i] - 'a';
            chars[tmp]++;
            if (chars[tmp] == 1) cnt++;
            tmp = s[i - minSize] - 'a';
            chars[tmp]--;
            if (chars[tmp] == 0) cnt--;
            if (cnt <= maxLetters) {
                counts[s.substr(i - minSize + 1, minSize)]++;
            }
        }
        int res = 0;
        for (auto& it : counts) {
            res = max(res, it.second);
        }
        return res;
    }
};
int main() {
    system("pause");
    return 0;
}