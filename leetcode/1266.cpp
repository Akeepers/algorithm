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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size()<2)
            return 0;
        auto start=points[0];
        int res=0;
        for(int i=1;i<points.size();++i){
            auto cur=points[i];
            int a=abs(start[0]-cur[0]);
            int b=abs(start[1]-cur[1]);
            int m=max(a,b);
            res+=m;
            start=points[i];
        }
        return res;
    }
};

int main()
{

    system("pause");
    return 0;
}