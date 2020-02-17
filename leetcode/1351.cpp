/*
 * @Author: yangpan
 * @Date: 2020-02-17 12:53:56
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-17 12:54:12
 * @Description: file content
 * @FilePath: \leetcode\1351.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j =0;j<n;++j){
                if(grid[i][j]<0){
                    cnt+=n-j;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    system("pause");
    return 0;
}