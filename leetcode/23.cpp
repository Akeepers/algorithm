#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(0);
        ListNode *max = new ListNode(INT_MAX);
        ListNode *min = max;
        vector<bool> visited(lists.size(), false);
        int flag = 0;
        ListNode *cur = cur;
        while (flag < lists.size())
        {
            for (int i = 0; i < lists.size(); ++i)
            {
                if (visited[i])
                    continue;
                if (lists[i] == nullptr)
                {
                    visited[i] = true;
                    flag++;
                    if (flag == lists.size())
                        break;
                    continue;
                }
                if (lists[i]->val < min->val)
                {
                    min = lists[i];
                    cur = lists[i];
                }
              
                head->next = min;
                head = head->next;
                cur = cur->next;
                head->next = nullptr;
            }
            min = max;
            cur = max;
        }
        return head->next;
    }
};

int main()
{
    system("pause");
    return 0;
}