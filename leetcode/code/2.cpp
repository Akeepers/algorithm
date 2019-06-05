#include <iostream>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto head = new ListNode(0);
        auto node = head;
        auto add = 0;
        auto val = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            val = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + add;
            add = val / 10;
            node->val = val%10;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            if (l1 != nullptr ||  l2 != nullptr){
                node->next = new ListNode(0);
                node = node->next;
            }
        }
        //Boundary conditions, such as l1 is [5] and l2 is [5]. 
        if(add>0){
            node->next = new ListNode(1);
            node = node->next;
        }
        return head;
    }
};

int main()
{
    auto node1 = new ListNode(2);
    auto node2 = new ListNode(4);
    auto node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    auto node4 = new ListNode(5);
    auto node5 = new ListNode(6);
    auto node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;
    Solution solution;
    auto result = solution.addTwoNumbers(node1, node4);
    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
    system("pause");
    return 0;
}