#include <iostream>
#include <vector>
// #include <pair>

using namespace std;

int getCount(pair<int, int> &order, vector<bool> visited)
{
    int count = 0;
    for (int i = order.first; i <= order.second; ++i)
    {
        if (!visited[i])
        {
            count++;
            visited[i] = true;
        }
    }
    return count;
}
void visit(pair<int, int> &order, vector<bool> visited)
{
    for (int i = order.first; i <= order.second; ++i)
    {
        visited[i] = true;
    }
}

int GetNoOverlapCount(pair<int, int> order1, pair<int, int> order2)
{
    int count = 0;
    for (int i = order2.first; i <= order2.second; ++i)
    {
        if (i < order1.first || i > order1.second)
        {
            count++;
        }
    }
    return count;
}

int getResult(int n, vector<pair<int, int>> requests)
{
    vector<int> dp(requests.size(), 0);
    dp[0] = INT_MAX;
    vector<bool> indexs(requests.size() + 1, false);
    int index = 0;
    for (int i = 0; i < requests.size(); ++i)
    {   
            auto temp=requests[i].second - requests[i].first+1;
            if(temp<dp[0]){
                dp[0] = temp;
                index = i;
            }
    }
    vector<bool> visited(n + 1, false);
    visit(requests[index], visited);
    for (int i = 1; i < requests.size(); ++i)
    {
        int count2 = INT_MAX;
        
        for (int j = 0; j < requests.size(); ++j)
        {
            if(indexs[j])
                continue;
            auto temp = getCount(requests[j], visited);
            if(temp<count2){
                count2 = temp;
                index = j;
            }
        }
        indexs[index] = true;
        visit(requests[index], visited);
        dp[i] = count2 > dp[i - 1] ? dp[i - 1] : count2;
    }
    return dp[requests.size()-1];
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, q, l, r;
        cin >> n >> q;
        vector<pair<int, int>> requests;
        while (q--)
        {
            cin >> l >> r;
            requests.push_back(make_pair(l, r));
        }
        cout << "Case #" << i << ": " << getResult(n, requests) << endl;
    }
    return 0;
}
