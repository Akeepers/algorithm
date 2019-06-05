#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
    int visit(const string &beginWord, const string &endWord, unordered_map<string, bool> &dicts)
    {
        vector<string> q1 = {beginWord};
        vector<string> q2 = {endWord};
        int length = 1;
        bool flag = true;
        while (true)
        {
            auto cur = q1.size() <= q2.size() ? q1 : q2;
            flag = q1.size() <= q2.size();
            length++;
            vector<string> next;
            for (auto word : cur)
            {
                auto temp = word;
                for (int i = 0; i < word.size(); ++i)
                {
                    int d = word[i] - 'a';

                    for (int j = 1; j < 26; ++j)
                    {
                        temp[i] = 'a' + (d + j) % 26;
                        if (dicts.find(temp) != dicts.end())
                        {
                            if (dicts[temp])
                            {
                                if (flag)
                                {

                                    if (find(q2.begin(), q2.end(), temp) != q2.end())
                                        return length;
                                }
                                else
                                {
                                    if (find(q1.begin(), q1.end(), temp) != q1.end())
                                        return length;
                                }
                            }
                            else
                            {
                                dicts[temp] = true;
                                next.emplace_back(temp);
                            }
                        }
                    }
                    temp = word;
                }
            }
            if (next.empty())
                break;
            if (flag)
                q1 = next;
            else
                q2 = next;
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
        if (dicts.find(endWord) == dicts.end())
            return 0;
        dicts[beginWord] = true;
        dicts[endWord] = true;
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
