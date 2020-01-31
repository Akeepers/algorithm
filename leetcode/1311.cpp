/*
 * @Author: yangpan
 * @Date: 2020-01-30 20:07:34
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-01-30 20:30:54
 * @Description: file content
 * @FilePath: \leetcode\1311.cpp
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
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        vector<string> result;
        queue<int> q;
        unordered_map<string, int> videos;
        vector<pair<int, string>> tmp;
        q.push(id);
        visited[id] = true;

        while (!q.empty() && level--) {
            int len = q.size();
            while (len--) {
                auto top = q.front();
                q.pop();
                for (auto& next : friends[top]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        while (!q.empty()) {
            for (auto& video : watchedVideos[q.front()]) {
                videos[video]++;
            }
            q.pop();
        }
        for (auto& it : videos) {
            tmp.emplace_back(it.second, it.first);
        }
        sort(tmp.begin(), tmp.end());
        transform(tmp.begin(), tmp.end(), back_inserter(result),
                  [](pair<int, string>& p) { return p.second; });
        return result;
    }
};
int main() {
    system("pause");
    return 0;
}