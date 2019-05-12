#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
private:
    int visit(const string &beginWord, const string &endWord, unordered_map<string, bool> &dicts)
    {
        vector<string> q1 = {beginWord};
        int length = 0;
        while (true)
        {
            length++;
            vector<string> next;
            for (auto word : q1)
            {
                auto temp = word;
                for (int i = 0; i < beginWord.size(); ++i)
                {
                    int d = word[i] - 'a';

                    for (int j = 1; j < 26; ++j)
                    {
                        temp[i] = word[i] + (d + j) % 26;
                        if (dicts.find(temp) != dicts.end() && !dicts[temp])
                        {
                            if (temp == endWord)
                                return length;
                            dicts[temp] = true;
                            next.emplace_back(temp);
                        }
                    }
                    temp = word;
                }
            }
            if (next.empty())
                break;
            q1 = next;
        }
        return 0;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord.empty() || endWord.empty() || beginWord == endWord)
            return 0;
        unordered_map<string, bool> dicts;
        for (auto word : wordList)
            dicts.insert(pair<string, bool>(word, false));
        return visit(beginWord, endWord, dicts);
    }
};

int main()
{

    string begin = "hit";
    string end = "cog";
    vector<string> list = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution solution;
    solution.ladderLength(begin, end, list);
    system("pause");
    return 0;
}
