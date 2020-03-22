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
   public:
    string predictPartyVictory(string senate) {
        int activate_r = 0, activate_d = 0;
        vector<bool> activate(senate.length(), true);
        for (int i = 0; i < senate.length(); ++i) {
            if ('R' == senate[i]) {
                activate_r++;
                if (activate_r <= 0) {
                    activate[i] = false;
                } else {
                    activate_d--;
                }
            } else {
                activate_d++;
                if (activate_d <= 0) {
                    activate[i] = false;
                } else {
                    activate_r--;
                }
            }
        }
        if (activate_r != activate_d) {
            return activate_r > activate_d ? "Radiant" : "Dire";
        } else {
            string res = "";
            for (int i = 0; i < senate.length(); ++i) {
                if (!activate[i]) {
                    continue;
                }
                if ('R' == senate[i]) {
                    if (--activate_d == 0) {
                        res = "Radiant";
                        break;
                    }
                } else {
                    if (--activate_r == 0) {
                        res = "Dire";
                        break;
                    }
                }
            }
            return res;
        }
    }
};

int main() {
    Solution s;
    s.predictPartyVictory("DRRDRDRDRDDRDRDR");
    system("pause");
    return 0;
}