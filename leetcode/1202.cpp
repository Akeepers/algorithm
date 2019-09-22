#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Solution
{
    void dfs(vector<vector<int>> &g, int cur, vector<int> &indexs, vector<bool> &visited)
    {
        indexs.emplace_back(cur);
        visited[cur] = true;
        for (auto i : g[cur])
        {
            if (!visited[i])
                dfs(g, i, indexs, visited);
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<vector<int>> graph(n);
        for (auto pair : pairs)
        {
            graph[pair[0]].emplace_back(pair[1]);
            graph[pair[1]].emplace_back(pair[0]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
                continue;
            vector<int> indexs;
            dfs(graph, i, indexs, visited);
            sort(indexs.begin(), indexs.end());
            vector<char> tmp;
            for (auto index : indexs)
            {
                tmp.emplace_back(s[index]);
            }
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < indexs.size(); ++j)
            {
                s[indexs[j]] = tmp[j];
            }
        }
        return s;
    }
};

int main()
{
    system("pause");
    return 0;
}