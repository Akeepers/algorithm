#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

class Solution {
    bool check(int m,int n,int x,int y){
        return x<m&&x>=0&&y<n&&y>=0;
    }
    
    void dfs(vector<vector<int>>& grid,int x,int y,int& len){
        len++;
        grid[x][y]=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<4;++i){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(check(m,n,x1,y1)&&grid[x1][y1]==1){
                dfs(grid,x1,y1,len);
            }
        }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        int m=grid.size(),n=grid[0].size();
        int res=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                // if(grid[i][j]==1)
                // {
                //     int cur=0;
                //     dfs(grid,i,j,cur);
                //     res+=cur>1?cur:0;
                // }
            }
        }
        return res;
        
    }
};

int main()
{

    system("pause");
    return 0;
}