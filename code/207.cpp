#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node
{
    int id;
    Node *next;
    Node(int _id) : id(_id), next(nullptr) {}
};

class Solution
{
  private:
    void makeGraph(int numCourses, vector<pair<int, int>> &prerequisites, vector<vector<int>> &graph, vector<int> &degrees)
    {
        for (auto pre : prerequisites)
        {
            graph[pre.second].push_back(pre.first);
            degrees[pre.first]++;
        }
    }
    bool topologicalSort(vector<vector<int>> &graph, vector<int> &degrees)
    {
        stack<int> noPre;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees[i] == 0)
                noPre.push(i);
        }
        int count = 0;
        while(!noPre.empty()){
            int id = noPre.top();
            noPre.pop();
            count++;
            for(auto item:graph[id]){
                if(--degrees[item]==0)
                    noPre.push(item);
            }
        }
        return count == degrees.size();
    }

  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degrees(numCourses, 0);
        makeGraph(numCourses, prerequisites, graph, degrees);
        return topologicalSort(graph, degrees);
    }
};

int main()
{
    Solution solution;
    vector<pair<int, int>> vec;
    vec.push_back(make_pair(3, 0));
    vec.push_back(make_pair(0, 1));
    cout << (solution.canFinish(4, vec) ? "true" : "false") << endl;
    system("pause");
    return 0;
}
