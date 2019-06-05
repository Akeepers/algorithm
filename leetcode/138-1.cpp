#include <iostream>
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
    int getDepth(Node *root, Node *node)
    {
        int depth = 0;
        Node *temp = root;
        while (temp != node)
        {
            temp = temp->next;
            depth++;
        }
        return depth;
    }
    Node *getNode(Node *root, int depth)
    {
        Node *node = root;
        while (depth--)
            node = node->next;
        return node;
    }

  public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        //copy val and next
        Node *root = new Node(head->val, head->next, nullptr);
        Node *node = root;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            node->next = new Node(temp->val, temp->next, nullptr);
            node = node->next;
        }

        //copy random pointer
        node = root;
        temp = head;
        while (temp != nullptr)
        {
            node->random = temp->random == nullptr ? nullptr : getNode(root, getDepth(head, temp->random));
            temp = temp->next;
            node = node->next;
        }
        return root;
    }
};

int main()
{
    system("pause");
    return 0;
}