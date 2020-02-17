/*
 * @Author: yangpan
 * @Date: 2020-02-08 17:37:48
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-08 17:38:35
 * @Description: file content
 * @FilePath: \leetcode\647.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),result=0;
        if(n<2) return n;
        for(int i=0;i<n;++i){
            int l=i,r=i;
            while(l>=0&&r<n&&s[l--]==s[r++])
                result++;
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l--]==s[r++])
                result++;
        }    
        return result;
    }
};

int main()
{
    system("pause");
    return 0;
}