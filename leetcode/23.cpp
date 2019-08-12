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

bool mycompare(const ListNode *a, const ListNode *b)
{
    return a->val > b->val;
}

//minHeap
class Solution1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto head = new ListNode(0);
        auto node = head;
        vector<ListNode *> minHeap;
        for (auto item : lists)
        {
            if (item != nullptr)
                minHeap.emplace_back(item);
        }
        make_heap(minHeap.begin(), minHeap.end(), mycompare);
        while (!minHeap.empty())
        {
            node->next = minHeap.front();
            node = node->next;
            auto next = minHeap.front()->next;
            node->next = nullptr;
            pop_heap(minHeap.begin(), minHeap.end(), mycompare);
            minHeap.pop_back();
            if (next != nullptr)
            {
                minHeap.push_back(next);
                push_heap(minHeap.begin(), minHeap.end(), mycompare);
            }
        }
        return head->next;
    }
};

//divide and conquer
class Solution2
{
    private:
    ListNode* mergeTwoLists(ListNode* root1,ListNode* root2){
        if(root1==nullptr||root2==nullptr)
            return root1 == nullptr ? root2 : root1;
        auto root = new ListNode(0);
        auto node = root;
        while (root1 != nullptr && root2 != nullptr)
        {
            if(root1->val<root2->val){
                node->next = root1;
                node = node->next;
                root1 = root1->next;
            }else{
                node->next = root2;
                node=node->next;
                root2 = root2->next;
            }
        }
        node->next = root1 == nullptr ? root2 : root1;
        return root->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode* head = nullptr;
        for(auto item:lists){
            head = mergeTwoLists(head, item);
        }
        return head;
    }
};



int main()
{
    ListNode *node1 = new ListNode(1);
    auto node = node1;
    node->next = new ListNode(4);
    node = node->next;
    node->next = new ListNode(5);
    node = node->next;

    ListNode *node2 = new ListNode(1);
    node = node2;
    node->next = new ListNode(3);
    node = node->next;
    node->next = new ListNode(4);
    node = node->next;

    ListNode *node3 = new ListNode(2);
     node = node3;
    node->next = new ListNode(6);
    node = node->next;

    vector<ListNode *> inputs = {node1, node2, node3};

    Solution solution;
    solution.mergeKLists(inputs);
    system("pause");
    return 0;
}