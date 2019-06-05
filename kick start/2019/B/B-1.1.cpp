#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string &str, pair<int, int> &pair)
{
    int length = pair.second - pair.first + 1;
    if (length == 1)
        return true;
    vector<int> characterCounts(26, 0);
    int oddCount = length % 2;
    for (int i = pair.first; i <= pair.second; ++i)
    {
        characterCounts[str[i] - 'A']++;
    }
    for (auto item : characterCounts)
    {
        if (item % 2 == 0)
            continue;
        oddCount--;
        if (oddCount < 0)
            return false;
    }
    return true;
}

int countPalindromes(vector<pair<int, int>> &inputs, string &str, int length)
{
    int count = 0;
    for (auto pair : inputs)
    {
        if (isPalindrome(str, pair))
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