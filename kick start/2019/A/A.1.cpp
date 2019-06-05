#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getResult(vector<int>& scores,int p){
    sort(scores.begin(), scores.end());
    vector<int> dp(p + 1, 0);
    int count = INT_MAX;
    for (int i = 0; i+p-1 <scores.size();++i){
        int temp = 0;
        for (int j = i; j <p+i ;++j){
            temp += scores[i + p - 1] - scores[j];
        }
        if(count>temp)
            count = temp;
    }
    return count;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, p,score;
        cin >> n >> p;
        vector<int> scores;
        while (n--)
        {
            cin >> score;
            scores.push_back(score);
        }
        cout << "Case #" << i << ": " << getResult(scores, p) << endl;
        ;
    }
    return 0;
}
