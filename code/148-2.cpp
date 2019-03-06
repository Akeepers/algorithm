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
  private:
    ListNode *getMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto slow = head, quick = head;
        while (quick->next != nullptr && quick->next->next != nullptr)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }

    ListNode *mergeSort(ListNode *left, ListNode *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        ListNode *head = nullptr;
        if (left->val < right->val)
        {
            head = left;
            left = left->next;
        }
        else
        {
            head = right;
            right = right->next;
        }
        auto node = head;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                node->next = left;
                node = node->next;
                left = left->next;
            }
            else
            {
                node->next = right;
                node = node->next;
                right = right->next;
            }
        }
        if (left != nullptr)
            node->next = left;
        if (right != nullptr)
            node->next = right;
        return head;
    }

  public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto mid = getMiddle(head);
        auto right = mid->next;
        mid->next = nullptr;
        return mergeSort(sortList(head), sortList(right));
    }
};

int main()
{
    system("pause");
    return 0;
}
