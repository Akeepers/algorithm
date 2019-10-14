#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<int> cur(n+1,0);
        cur[n]=-1;
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cur[j]=matrix[i][j]=='1'?cur[j]+1:0;
            }
            int k=0;
            stack<int> indexs;
            while (k <= n)
            {
                if (indexs.empty() || cur[k] >= cur[indexs.top()])
                    indexs.push(k++);
                else
                {
                    int t = indexs.top();
                    indexs.pop();
                    int area = cur[t] * (indexs.empty() ? k : (k - indexs.top() - 1));
                    res= max(res, area);
                }
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