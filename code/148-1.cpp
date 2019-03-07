#include <iostream>

using namespace std;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:
    ListNode* partition(ListNode* key,ListNode* end){
        auto p1=key;
        auto p2 = key->next;
        while(p2!=end){
            if(p2->val<key->val){
                p1 = p1->next;
                auto temp = p1->val;
                p1->val = p2->val;
                p2->val = temp;
            }
            p2 = p2->next;
        }
        if(p1!=key){
            auto temp=key->val;
            key->val=p1->val;
            p1->val = temp;
        }
        return p1;
    }
    void quickSort(ListNode* head,ListNode* end){
        if(head!=end){
            auto node = partition(head, end);
            quickSort(head, node);
            quickSort(node->next, end);
        }
    }
    
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }
};

int main(){
    system("pause");
    return 0;
}
