/*
 * @Author: yangpan
 * @Date: 2020-01-31 16:05:49
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-01-31 20:16:30
 * @Description: file content
 * @FilePath: \leetcode\1319.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
   private:
    std::vector<int> _parents;
    int _len;

   public:
    UnionFind(int n) {
        _len = n;
        _parents.resize(n);
        for (int i = 0; i < n; ++i) {
            _parents[i] = i;
        }
    }
    int find(int u) {
        if (_parents[u] != u) {
            _parents[u] = find(_parents[u]);
        }
        return _parents[u];
    }
    void unin(int u, int v) {
        int fau = find(u);
        int fav = find(v);
        _parents[fav] = fau;
    }

    int get_connected_component_cnt() {
        int cnt = -1;
        for (int i = 0; i < _len; ++i) {
            if (i != _parents[i]) cnt++;
        }
        return cnt;
    }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        auto uf = UnionFind(n);
        for (auto& connection : connections) {
            uf.unin(connection[0], connection[1]);
        }
        return uf.get_connected_component_cnt();
    }
};
int main() {
    system("pause");
    return 0;
}