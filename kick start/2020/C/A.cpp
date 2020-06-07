#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

bool DFS(const vector<vector<char>>& graphs,
         vector<vector<pair<int, int>>>& dict, vector<char> nexts,
         vector<bool>& visited, string& ans, int depth, char c) {
    int m = graphs.size();
    int n = graphs[0].size();
    visited[c - 'A'] = true;
    depth++;
    ans += c;
    for (auto pos : dict[c - 'A']) {
        auto i = pos.first;
        auto j = pos.second;
        if (i == m - 1) {
            continue;
            // } else if (j == n - 1) {
            //     if (graphs[i + 1][j] == c || visited[graphs[i + 1][j] - 'A'])
            //     {
            //         continue;
            //     } else {
            //         visited[c - 'A'] = false;
            //         return false;
            //     }
        } else {
            if (graphs[i + 1][j] == c || visited[graphs[i + 1][j] - 'A']) {
                continue;
            } else {
                visited[c - 'A'] = false;
                ans.pop_back();
                return false;
            }
        }
    }
    if (depth == nexts.size()) {
        return true;
    }
    for (auto next : nexts) {
        if (!visited[next - 'A']) {
            if (DFS(graphs, dict, nexts, visited, ans, depth, next)) {
                return true;
            }
        }
    }
}

void slove() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> graphs(r, vector<char>(c));
    vector<char> items;
    vector<vector<pair<int, int>>> dict(26);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> graphs[i][j];
            dict[graphs[i][j] - 'A'].push_back({i, j});
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!dict[i].empty()) {
            items.emplace_back('A' + i);
        }
    }
    unordered_set<char> cur_visited;
    string res = "";
    for (int i = 0; i < c; ++i) {
        string cur = "";
        if (cur_visited.count(graphs[r - 1][i]) == 0) {
            cur_visited.insert(graphs[r - 1][i]);
            vector<bool> visited(26, false);
            int depth = 0;
            if (DFS(graphs, dict, items, visited, cur, depth,
                    graphs[r - 1][i])) {
                res = cur;
                break;
            }
        }
    }
    if (res.empty()) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}
int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        slove();
    }
    return 0;
}
