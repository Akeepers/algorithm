#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node *, Node *> hashTable;
        Node *node = head;
        while (node != nullptr)
        {
            hashTable[node]=new Node(node->val, nullptr, nullptr);
            node = node->next;
        }
        node = head;
        while (node != nullptr)
        {
            hashTable[node]->next = hashTable[node->next];
            if(node->random!=nullptr)
                 hashTable[node]->random = hashTable[node->random];
            node = node->next;
        }
        return hashTable[head];
    }
};

int main()
{
    system("pause");
    return 0;
}