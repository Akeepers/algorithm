#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto item : prerequisites)
        {
            graph[item[1]].emplace_back(item[0]);
            inDegree[item[0]]++;
        }

        stack<int> s;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
                s.push(i);
        }

        int visited = 0;
        vector<int> order;
        while (!s.empty())
        {
            int cur = s.top();
            s.pop();
            order.push_back(cur);
            visited++;
            for (auto node : graph[cur])
            {
                if (--inDegree[node] == 0)
                    s.push(node);
            }
        }
        if (visited != numCourses)
        {
            vector<int> ret;
            return ret;
        }
        return order;
    }

private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph;
        for (auto item : prerequisites)
        {
            graph[item[0]].emplace_back(item[1]);
        }
        return graph;
    }
};

int main()
{
    system("pause");
    return 0;
}