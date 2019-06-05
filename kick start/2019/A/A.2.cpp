#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getDist(vector<vector<int>> &grid, vector<vector<int>> &dist, pair<int, int> pos, int m, int n)
{
    if (pos.first < 0 || pos.first >= m || pos.second < 0 || pos.second >= n)
        return INT_MAX;
    if (grid[pos.first][pos.second] == 1)
    {
        dist[pos.first][pos.second] = 0;
        return 0;
    }
    else
    {
        int d = INT_MAX;
        if (pos.first - 1 >= 0)
        {
            auto temp = dist[pos.first - 1][pos.second] != -1 ? dist[pos.first - 1][pos.second] : 1 + getDist(grid, dist, make_pair(pos.first - 1, pos.second), m, n);
            if (temp < d)
                d = temp;
        }
        if (pos.first + 1 < m)
        {
            auto temp = dist[pos.first + 1][pos.second] != -1 ? dist[pos.first + 1][pos.second] : 1 + getDist(grid, dist, make_pair(pos.first + 1, pos.second), m, n);
            if (temp < d)
                d = temp;
        }
        if (pos.second - 1 >= 0)
        {
            auto temp = dist[pos.first][pos.second - 1] != -1 ? dist[pos.first][pos.second - 1] : 1 + getDist(grid, dist, make_pair(pos.first, pos.second - 1), m, n);
            if (temp < d)
                d = temp;
        }
        if (pos.second + 1 < n)
        {
            auto temp = dist[pos.first][pos.second + 1] != -1 ? dist[pos.first][pos.second + 1] : 1 + getDist(grid, dist, make_pair(pos.first, pos.second + 1), m, n);
            if (temp < d)
                d = temp;
        }
        return d;
    }
}

int calDist(pair<int, int> pos1,pair<int, int> pos2){
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int getResult(int m,int n, vector<string> inputs)
{
    vector<vector<int>> grid(m, vector<int>(n, 0));
    int i = 0;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    vector<pair<int, int>> maxPos(0);
    int max=0;
    for (auto input : inputs)
    {
        int j = 0;
        for (auto item : input)
        {
            grid[i][j++] = item - '0';
        }
        i++;
    }
    for (int i = 0; i < m;++i){
        for (int j = 0; j < n;++j){
            getDist(grid, dist, make_pair(i, j), m, n);
            if(max<dist[i][j]){
                max = dist[i][j];
                maxPos.clear();
                maxPos.push_back(make_pair(i, j));
            }
            if(max==dist[i][j]){
                maxPos.push_back(make_pair(i, j));
            }
        }
    }
    if(max==0)
        return 0;
    for (int i = 0; i < m;++i){
        for (int j = 0; j < n;++j){
           if(grid[i][j]==0){
               int temp = INT_MAX;
               for(auto item:maxPos){
                   auto ret = calDist(make_pair(i, j), item);
                   if(ret<temp)
                       temp = ret;
               }
               if(max>temp)
                   max = temp;
           }
        }
    }
    return max;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, m,q;
        string temp;
        cin >> m >> n;
        vector<string> inputs;
        q = m;
        while (q--)
        {
            cin >> temp;
            inputs.push_back(temp);
        }
        cout << "Case #" << i << ": " << getResult(m,n, inputs) << endl;
    }
    return 0;
}
