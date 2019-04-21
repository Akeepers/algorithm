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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *firstOdd = head;
        ListNode *firstEven = firstOdd->next;
        ListNode *even = firstEven;
        ListNode *odd = firstOdd;
        while (even != nullptr)
        {
            if (even->next == nullptr)
                break;
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        if (even != nullptr)
            node->next = nullptr;
        odd->next = even;
        return head;
    }
};
int main()
{
    system("pause");
    return 0;
}