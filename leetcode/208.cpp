#include <iostream>

using namespace std;

class Trie
{
  private:
    struct Node
    {
        char val;
        Node *next[26];
        bool isEnd;
        Node(char _val) : val(_val), isEnd(false)
        {
            for (int i = 0; i < 26; ++i)
            {
                next[i] = nullptr;
            }
        }
    };
    Node *root;

  public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node(NULL);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if(word.empty()) return;
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
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto node = root;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
                return false;
            node = node->next[c - 'a'];
        }
        if (!node->isEnd)
            return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto node = root;
        for (auto c : prefix)
        {
            if (node->next[c - 'a'] == nullptr)
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main()
{
    Trie trie;

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");
    trie.search("app"); // returns true
    system("pause");
    return 0;
}
