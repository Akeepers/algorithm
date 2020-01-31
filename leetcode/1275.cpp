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
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8, 0), B(8, 0);
        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0], c = moves[i][1];
            vector<int>& player = (i % 2 == 0) ? A : B;
            player[r]++;
            player[c + 3]++;
            if (r == c) player[6]++;
            if (r == 2 - c) player[7]++;
        }
        for (int i = 0; i < 8; i++) {
            if (A[i] == 3) return "A";
            if (B[i] == 3) return "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
int main() {
    system("pause");
    return 0;
}