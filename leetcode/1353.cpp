/*
 * @Author: yangpan
 * @Date: 2020-02-17 12:53:56
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-17 12:59:33
 * @Description: file content
 * @FilePath: \leetcode\1351.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> q;
        int i=0,n=events.size(),res=0;
        for(int d=1;d<=100000;++d){
            while(i<n&&events[i][0]==d)
                q.push(events[i++][1]);
            while(!q.empty()&&q.top()<d)
                q.pop();
            if(!q.empty()){
                res++;
                q.pop();
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}