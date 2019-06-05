#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        string str;
        vector<pair<int, int>> inputs;
        int length = 0, questions = 0;
        int left = 0, right = 0;
        cin >> length >> questions;
        cin >> str;
        while (questions--)
        {
            cin >> left >> right;
            inputs.emplace_back(make_pair(left - 1, right - 1));
        }
        int ret;
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}