#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct _TrieNode {
    int num;
    vector<_TrieNode*> childs;
    _TrieNode() {
        num = 0;
        childs.resize(26, nullptr);
    }
} TrieNode;

class TrieTree {
   public:
    TrieNode* root;
    int k;
    void insert(const string& str) {
        if (str.empty()) return;
        auto p = root;
        for (int i = 0; i < str.size(); ++i) {
            int cur = str[i] - 'A';
            if (p->childs[cur] == nullptr) {
                p->childs[cur] = new TrieNode();
            }
            p = p->childs[cur];
            p->num++;
        }
    }
    ll get_result() {
        ll result = 0;
        queue<TrieNode*> next;
        next.push(root);
        while (!next.empty()) {
            auto cur = next.front();
            next.pop();
            for (auto child : cur->childs) {
                if (child == nullptr || child->num < k) continue;
                result += child->num / k;
                next.push(child);
            }
        }
        return result;
    }
    TrieTree(int _k) {
        root = new TrieNode();
        k = _k;
    }
    ~TrieTree() {
        queue<TrieNode*> next;
        next.push(root);
        while (!next.empty()) {
            auto cur = next.front();
            next.pop();
            for (auto child : cur->childs) {
                if (child == nullptr) continue;
                next.push(child);
            }
            delete cur;
        }
    }
};
void slove() {
    ll n, k;
    cin >> n >> k;

    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    TrieTree tree(k);
    for (auto str : strs) {
        tree.insert(str);
    }
    cout << tree.get_result() << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        slove();
    }
    system("pause");
    return 0;
}
