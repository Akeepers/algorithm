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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *root = nullptr;
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            root = l1;
            l1 = l1->next;
        }
        else
        {
            root = l2;
            l2 = l2->next;
        }
        ListNode *node = root;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
                node = node->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
                node = node->next;
            }
        }
        if (l1 != nullptr)
            node->next = l1;
        else
            node->next = l2;
        return root;
    }
};

int main()
{
    system("pause");
    return 0;
}
