#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

int prim(int n, int s, vector<vector<int>>& G,vector<bool>& vis, vector<int>& d)
{
	fill(d.begin(), d.end(), INF);
	fill(vis.begin(), vis.end(), false);
	d[s] = 0;					   
	int sum = 0;				  
	for (int i = 0; i < n; ++i)
	{
		int u = -1;					//u使得d[u]最小
		int MIN = INF;				//记录最小的d[u]
		for (int j = 0; j < n; ++j) //开始寻找最小的d[u]
		{
			if (vis[j] == false && d[j] < MIN)
			{
				MIN = d[j];
				u = j;
			}
		}
		//找不到小于INF的d[u]，则剩下的顶点与集合S不连通
		if (u == -1)
			return -1;
		vis[u] = true; //标记u为已访问
		sum += d[u];   //将与集合S距离最小的边加入到最小生成树
		for (int v = 0; v < n; ++v)
		{
			//v未访问 && u能够到达v && 以u为中介点可以使v离集合S更近
			if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
				d[v] = G[u][v]; //更新d[v]
		}
	}
	return sum; //返回最小生成树的边权之和
}

int main()
{

	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		
		int n, m;
		cin >> n >> m;
		vector<vector<int>> graph(n, vector<int>(n, 2));
		for (int j = 0; j < m; j++)
		{
			int x1, x2;
			cin >> x1 >> x2;
			graph[x1-1][x2-1] = 1;
			graph[x2-1][x1-1] = 1;
		}
		int res = INT_MAX;
		vector<bool> vis(n);
		vector<int> d(n);
		for (int j = 0; j < n;++j){
			res = min(res, prim(n, j, graph,vis,d));
		}
		cout << "Case #" << i << ": "<<res<< endl;
	}
	return 0;
}
