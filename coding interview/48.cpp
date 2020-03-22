#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();
        unordered_map<char, int> counts;
        int res = 0, l = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (++counts[s[i]] > 1) {
                res = max(res, i - l);
                while (--counts[s[l++]] != 1) {
                }
            }
        }
        res = max(res, n - l);
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}