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
    int countServers(vector<vector<int>>& grid) 
    {
        vector<int> rows(grid.size(),0),columns(grid[0].size(),0);	
        for(int i=0;i<grid.size();i++)						
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j])
                    rows[i]++,columns[j]++;
        int result=0;
        for(int i=0;i<grid.size();i++)			
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]&&(columns[j]>1||rows[i]>1))	
                    result++;
        return result;
    }
};

int main()
{

    system("pause");
    return 0;
}