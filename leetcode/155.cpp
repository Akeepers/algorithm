#include <iostream>

using namespace std;

class Node
{
  public:
    int val;
    Node *next;
    Node *min;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        min = nullptr;
    }
};

class MinStack
{
  private:
    Node *head;
    Node *min;
    int stackSize;

  public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = nullptr;
        min = nullptr;
        stackSize = 0;
    }

    void push(int x)
    {
        Node *node = new Node(x);
        node->next = head;
        head = node;
        stackSize++;
        if(min==nullptr||min->val>head->val){
            head->min = min;
            min = head;
        }
    }
    void pop()
    {
        Node *temp = head;
        head = head->next;
        if(temp==min){
            min = min->min;
        }
        delete(temp);
        stackSize--;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return min->val;
    }
};

int main(){
    MinStack minStacl;
    return 0;
}