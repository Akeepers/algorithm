#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        auto slow = newHead, fast = head;
        while (n--)
            fast = fast->next;
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};
int main()
{
    system("pause");
    return 0;
}