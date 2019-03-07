#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *result = nullptr;
        if (head != nullptr)
        {
            result = new ListNode(head->val);
            head = head->next;

            while (head != nullptr)
            {
                auto node = new ListNode(head->val);
                node->next = result;
                result = node;
                head = head->next;
            }

            return result;
        }
    }
};

int main()
{
    system("pause");
    return 0;
}
