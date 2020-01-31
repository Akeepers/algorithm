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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ret = 0;
        vector<vector<int>> distance(n, vector<int>(n, INF));
        for (auto& edge : edges) {
            distance[edge[0]][edge[1]] = distance[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] =
                        min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        int num = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    cur++;
                }
            }
            if (cur < num) {
                num = cur;
                ret = i;
            }
        }
        return ret;
    }
};

int main() {
    system("pause");
    return 0;
}