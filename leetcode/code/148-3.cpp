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
        if (head == nullptr)
            return head;
        auto slow = head, quick = head;
        while (quick->next != nullptr && quick->next=->next != nullptr)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }

    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode head(0);
        auto headPtr = &head;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                headPtr->next = left;
                left = left->next;
            }
            else
            {
                headPtr->next = right;
                right = right->next;
            }
            headPtr = headPtr->next;
        }
        headPtr->next = left != nullptr ? left : right;
        return head.next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head==nullptr||head->next==nullptr)
            return head;
        auto mid = getMiddle(head);
        auto sortedPost = mergeSort(mid->next);
        mid->next = nullptr;
        auto sortedPre = mergeSort(head);
        return mergeList(sortedPre, sortedPost);
    }

  public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        return mergeSort(head);
    }
};

int main()
{
    system("pause");
    return 0;
}
