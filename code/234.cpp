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
private:
    ListNode *reverse(ListNode *node)
    {
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        ListNode *cur = node;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        auto slow = head;
        auto fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto node = reverse(slow->next);
        while (node != nullptr)
        {
            if (head->val != node->val)
                return false;
            head = head->next;
            node = node->next;
        }
        return true;
    }
};

int main()
{
    system("pause");
    return 0;
}