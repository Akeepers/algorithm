#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

class Solution
{
    bool toposort(vector<int> &nodes, map<int, set<int>> &graph, map<int, int> &inDegree)
    {
        vector<int> result;
        queue<int> q;
        for (int node : nodes)
        {
            if (!inDegree[node])
            {
                q.push(node);
            }
        }
        while (!q.empty())
        {
            int from = q.front();
            q.pop();
            result.push_back(from);
            for (int to : graph[from])
            {
                if (!(--inDegree[to]))
                {
                    q.push(to);
                }
            }
        }

        if (result.size() != nodes.size())
            return false;
        for (int i = 0; i < nodes.size(); i++)
            nodes[i] = result[i];
        return true;
    }

    map<int, vector<int>> group2items;
    map<int, set<int>> groupGraph;
    map<int, int> groupInDegree;
    map<int, set<int>> itemGraph;
    map<int, int> itemInDegree;

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        int nextGroup = m;
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                group[i] = nextGroup++;
            }
            group2items[group[i]].push_back(i);
        }

        for (int to = 0; to < n; to++)
        {
            for (int from : beforeItems[to])
            {
                int fromGroup = group[from];
                int toGroup = group[to];
                if (fromGroup == toGroup)
                {
                    itemGraph[from].insert(to);
                    itemInDegree[to]++;
                }
                else
                {
                    if (!groupGraph[fromGroup].count(toGroup))
                    {
                        groupGraph[fromGroup].insert(toGroup);
                        groupInDegree[toGroup]++;
                    }
                }
            }
        }

        vector<int> groups(nextGroup);
        for (int i = 0; i < nextGroup; i++)
            groups[i] = i;
        if (!toposort(groups, groupGraph, groupInDegree))
            return {};

        vector<int> ans;
        for (int g : groups)
        {
            auto &items = group2items[g];
            if (!toposort(items, itemGraph, itemInDegree))
                return {};
            for (int i : items)
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    system("pause");
    return 0;
}