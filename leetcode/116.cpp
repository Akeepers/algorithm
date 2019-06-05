#include <iostream>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution {
private:
    void popluate(Node* node){
        if(node->left==nullptr)
            return;
        node->left->next = node->right;
        node->right->next = node->next == nullptr ? nullptr : node->next->left;
        popluate(node->left);
        popluate(node->right);
    }
public:
    Node* connect(Node* root) {
        root->next = nullptr;
        popluate(root);
        return root;
    }
};
int main(){
    system("pause");
    return 0;
}
