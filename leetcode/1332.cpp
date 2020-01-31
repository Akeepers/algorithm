#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
   public:
    int removePalindromeSub(string s) {
        if (s.length() < 2) {
            return s.length();
        }
        return s == string(s.rbegin(), s.rend()) ? 1 : 2;
    }
};

int main() {
    system("pause");
    return 0;
}