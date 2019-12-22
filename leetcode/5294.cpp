#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

hash<string> g_hash_func;

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        unordered_set<int> cur_keys;
        stack<int> cur_boxs;
        vector<int> visited(status.size(), false);
        int res = 0;
        for (auto box : initialBoxes)
        {
            visited[box] = true;
            cur_boxs.push(box);
            for (auto key : keys[box])
            {
                cur_keys.insert(key);
            }
            for (auto b : containedBoxes[box])
            {
                cur_boxs.push(b);
            }
        }
        stack<int> cans;
        while (!cur_boxs.empty())
        {
            int cur = cur_boxs.top();
            cur_boxs.pop();
            cans.push(cur);
            if (visited[cur])
                continue;
            visited[cur] = true;
            for (auto key : keys[cur])
            {
                cur_keys.insert(key);
            }
            for (auto b : containedBoxes[cur])
            {
                if (!visited[b])
                    cur_boxs.push(b);
            }
        }
        vector<int> visit(status.size(), false);
        while (!cans.empty())
        {
            auto cur = cans.top();
            cans.pop();
            if (!visit[cur] && (status[cur] == 1 || cur_keys.count(cur)))
            {
                res += candies[cur];
            }
            visit[cur] = true;
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}