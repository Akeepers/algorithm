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
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        int m = 0;
        int n = 0;
        auto nodeA = headA;
        while (nodeA != nullptr)
        {
            m++;
            nodeA = nodeA->next;
        }
        auto nodeB = headB;
        while (nodeB != nullptr)
        {
            n++;
            nodeB = nodeB->next;
        }

        nodeA = headA;
        nodeB = headB;
        if (m < n)
        {
            int d = n - m;
            while (d--)
                nodeB = nodeB->next;
        }
        else
        {
            int d = m - n;
            while (d--)
                nodeA = nodeA->next;
        }
        while ((nodeA != nullptr && nodeB != nullptr) && nodeA != nodeB)
        {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return (nodeA == nullptr || nodeB == nullptr) ? nullptr : nodeA;
    }
};

int main()
{
    system("pause");
    return 0;
}