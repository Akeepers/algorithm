#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    char val;
    vector<Node *> next;
    bool isEnd;
    int idx; // record the position in words arary.
    Node(char _val) : val(_val), isEnd(false), idx(-1)
    {
        next = vector<Node *>(26, nullptr);
    }
};

class Trie
{
  private:
    Node *root;

  public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node(NULL);
    }

    /** Inserts a word into the trie. */
    void insert(string word, int idx)
    {
        if (word.empty())
            return;
        auto node = root;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Node(c);
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
        node->idx = idx;
    }

    Node *getRoot()
    {
        return root;
    }
};
class Solution
{
  private:
    vector<vector<pair<int, int>>> buildIndex(vector<vector<char>> &board)
    {
        vector<vector<pair<int, int>>> indexs(26, vector<pair<int, int>>(0));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                indexs[board[i][j] - 'a'].push_back(pair<int, int>(i, j));
            }
        }
        return indexs;
    }
    void checkWord(pair<int, int> pos, vector<vector<char>> &board, vector<vector<bool>> &visited, Node *node, vector<string> &res, vector<string> &words)
    {
        if (node->next[board[pos.first][pos.second] - 'a'] == nullptr)
            return;
        if (node->next[board[pos.first][pos.second] - 'a']->val == board[pos.first][pos.second] && !visited[pos.first][pos.second])
        {
            if (node->next[board[pos.first][pos.second] - 'a']->isEnd)
            {
                res.push_back(words[node->next[board[pos.first][pos.second] - 'a']->idx]);
                node->next[board[pos.first][pos.second] - 'a']->isEnd = false; // mark that we have add this word into results.
            }
            visited[pos.first][pos.second] = true;
            if (pos.second - 1 >= 0)
                checkWord(pair<int, int>(pos.first, pos.second - 1), board, visited, node->next[board[pos.first][pos.second] - 'a'], res, words);
            if (pos.second + 1 < board[0].size())
                checkWord(pair<int, int>(pos.first, pos.second + 1), board, visited, node->next[board[pos.first][pos.second] - 'a'], res, words);
            if (pos.first - 1 >= 0)
                checkWord(pair<int, int>(pos.first - 1, pos.second), board, visited, node->next[board[pos.first][pos.second] - 'a'], res, words);
            if (pos.first + 1 < board.size())
                checkWord(pair<int, int>(pos.first + 1, pos.second), board, visited, node->next[board[pos.first][pos.second] - 'a'], res, words);
            visited[pos.first][pos.second] = false;
        }
        return;
    }

  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        vector<string> results;
        if (words.empty() || board.empty() || board[0].empty())
            return results;
        Trie trie;
        auto indexs = buildIndex(board);
        int i = 0;
        for (auto item : words)
            trie.insert(item, i++);
        auto root = trie.getRoot();
        vector<vector<bool>> visited(board.size(), vector<bool>(board.size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                checkWord(pair<int, int>(i, j), board, visited, root, results, words);
            }
        }

        return results;
    }
};

int main()
{
    vector<vector<char>> board = {{'a', 'a'}};
    vector<string> words = {"aa"};
    Solution solution;
    auto ret = solution.findWords(board, words);
    for (auto item : ret)
    {
        cout << item << endl;
    }
    system("pause");
    return 0;
}