#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ret = "";
        if(n==0)
            return ret;
        for (int i = 0; i < strs[0].size();++i){
            for (int j = 1; j < n;++j){
                if(i>=strs[j].size()||strs[0][i]!=strs[j][i])
                    return ret;
            }
            ret += strs[0][i];
        }
        return ret;
    }
};

int main(){
    system("pause");
    return 0;
}
