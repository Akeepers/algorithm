#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int charToAscii(char c)
{
    return c - 'a' + 97;
}

char asciiToChar(int num)
{
    return 'a' + (num - 97);
}
string transfer(const string& str){
    vector<int> digits(26, 0);
    for(auto c:str){
        digits[c - 'a']++;
    }
    string res = "";
    for(auto digit:digits){
        res += 'a' + digit;
    }
    return res;
}
void visit(string &str, int start, unordered_map<char, vector<string>> &dicts, unordered_map<string, string> trans, int& res)
{
    int n=str.size();
    if(start==n)
    {
        res++;
        return;
    }
    if(start>n||dicts[str[start]].empty())
        return;
    for(auto str:dicts[str[start]]){
        int pos = start + str.size() - 1;
        if(pos>=n)
            return;
        if(str.back()==str[pos]&&transfer(str.substr(start,pos+1))==trans[str])
            visit(str, pos+1, dicts, trans,res);      
    }    
}

int count(string& str,vector<string>& vecs)
{
    unordered_map<char, vector<string>> dicts;
    unordered_map<string, string> trans;
    sort(vecs.begin(), vecs.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    for(auto str:vecs){
        dicts[str[0]].emplace_back(str);
        trans[str] = transfer(str);
    }
    int res = 0;
    visit(str, 0, dicts, trans,res);
    return res;
}

string generateStr(char s1, char s2, int n, int a, int b, int c, int d)
{
    int x1 = charToAscii(s1), x2 = charToAscii(s2), x3 = 0;
    string ret(s1+s2);
    for (int i = 3; i <= n; ++i)
    {
        x3 = (a * x2 + b * x1 + c) % d;
        ret += asciiToChar(97 + (x3 % 26));
        x1 = x2;
        x2 = x3;
    }
    return ret;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        long long l, n, a, b, c, d;
        char s1, s2;
        cin >> l;
        vector<string> vecs(l);
        for (int j = 0; j < l; j++)
            cin >> vecs[j];
        cin >> s1 >> s2;
        cin >> n >> a >> b >> c >> d;
        string str = generateStr(s1, s2, n, a, b, c, d);
        auto ret = count(str,vecs);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}