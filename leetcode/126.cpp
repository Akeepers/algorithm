#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
private:
    void buildPaths(string beginWord,
                    string &endWord,
                    unordered_map<string, vector<string>> &nexts,
                    vector<string> &path,
                    vector<vector<string>> &paths)
    {
        if (beginWord == endWord)
            paths.push_back(path);
        else
            for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it)
            {
                path.push_back(*it);
                buildPaths(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
    bool visit(
        unordered_set<string> &forward,
        unordered_set<string> &backward,
        unordered_map<string, bool> &dicts,
        unordered_map<string, vector<string>> &nexts,
        bool &isForward)
    {
        isForward = !isForward;
        if (forward.empty())
            return false;
        if (forward.size() > backward.size())
            return visit(backward, forward, dicts, nexts, isForward);
        // for (auto it = forward.begin(); it != forward.end(); ++it)
        //     dicts[*it]=true;
        // for (auto it = backward.begin(); it != backward.end(); ++it)
        //     dicts[*it]=true;
        unordered_set<string> words3;
        bool isFinished = false;
        for (auto it = forward.begin(); it != forward.end(); ++it)
        {
            string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch)
            {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp)
                    {
                        if (backward.find(word) != backward.end())
                        {
                            isFinished = true;
                            dicts[word] = true;
                            isForward ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                        else if (!isFinished && dicts.find(word) != dicts.end() && !dicts[word])
                        {
                            words3.insert(word);
                            dicts[word] = true;
                            isForward ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                    }
                *ch = tmp;
            }
        }
        return isFinished || visit(backward, words3, dicts, nexts, isForward);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;

        if (beginWord.empty() || endWord.empty())
            return ans;
        vector<std::string> path(1, beginWord);
        if (beginWord == endWord)
        {
            ans.push_back(path);
            return ans;
        }
        unordered_map<string, bool> dicts;
        for (auto word : wordList)
            dicts.insert(pair<string, bool>(word, false));
        if (dicts.find(endWord) == dicts.end())
            return ans;
        dicts[beginWord] = true;
        dicts[endWord] = true;
        unordered_set<string> forward, backward;
        forward.insert(beginWord);
        backward.insert(endWord);

        unordered_map<string, vector<string>> nexts;
        bool isForward = false;
        if (visit(forward, backward, dicts, nexts, isForward))
            buildPaths(beginWord, endWord, nexts, path, ans);
        return ans;
    }
};

int main()
{

    system("pause");
    return 0;
}
