#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

hash<string> g_hash_func;

class Solution
{

public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        int res = 0;
        int i = 0, start = 0;
        unordered_map<char, int> count;
        unordered_map<size_t, int> ocurs;
        while (i < minSize)
        {
            count[s[i++]]++;
        }
        for (; i < s.length(); ++i)
        {
            start = i - minSize;
            if (count.size() <= maxLetters)
            {

                size_t hash_data = g_hash_func(s.substr(start, minSize));
                ocurs[hash_data]++;
                res = max(res, ocurs[hash_data]);
            }
            count[s[start]]--;
            if (count[s[start]] == 0)
                count.erase(s[start]);
            count[s[i]]++;

        }
         return res;
    }
};

int main()
{
    system("pause");
    return 0;
}