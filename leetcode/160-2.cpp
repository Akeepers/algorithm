#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto nodeA = headA;
        auto nodeB = headB;
        while (nodeA != nodeB)
        {
            nodeA = nodeA == nullptr ? headB : nodeA->next;
            nodeB = nodeB == nullptr ? headA : nodeB->next;
        }
        return nodeA;
    }
};

int main()
{
    system("pause");
    return 0;
}