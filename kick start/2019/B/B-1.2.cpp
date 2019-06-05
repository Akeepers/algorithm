#include <iostream>
#include <vector>

using namespace std;

int countPalindromes(vector<pair<int, int>> &inputs, string &str, int length)
{
    int count = 0;
    vector<int> characterCounts(26, 0);
    vector<vector<int>> vec;
    for (auto item : str)
    {
        vec.emplace_back(vector<int>(characterCounts));
        characterCounts[item - 'A']++;
    }
    for (auto pair : inputs)
    {
        if (pair.second == pair.first)
        {
            count++;
            continue;
        }
        int oddCount = (pair.second - pair.first + 1) % 2;
        int j = str[pair.second] - 'A';
        bool flag = false;
        for (int i = 0; i < 26; ++i)
        {
            int temp = vec[pair.second][i] - vec[pair.first][i];
            if (i == j)
                temp += 1;
            if (temp % 2 == 0)
                continue;
            oddCount--;
            if (oddCount < 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        count++;
    }
    return count;
}

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
        int ret = countPalindromes(inputs, str, length);

        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}