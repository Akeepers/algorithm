#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
  private:
    vector<int> stack;
    int stackSize;

  public:
    /** initialize your data structure here. */
    MinStack()
    {
        stackSize = 0;
    }

    void push(int x)
    {
        stack.push_back(x);
        stackSize++;
        if (stackSize == 1)
            return;
        int pos = stackSize - 1;
        bool flag = false;
        do
        {
            if (stack[pos / 2] > stack[pos])
            {
                int temp = stack[pos / 2];
                stack[pos / 2] = stack[pos];
                stack[pos] = temp;
                flag = true;
                pos = pos / 2;
                continue;
            }
            flag = false;
        } while (flag && pos != 0);
    }

    void pop()
    {
        if (stackSize == 0)
            return;
        stackSize--;
        stack[0] = stack[stackSize];
        stack.pop_back();
        int k = 1;
        int son = k * 2;
        while (son <= stackSize)
        {
            if (stack[k - 1] <= stack[son - 1])
                break;
            int temp = stack[k - 1];
            stack[k - 1] = stack[son - 1];
            stack[son - 1] = temp;
            k *= 2;
            son = k * 2;
        }
        k = 1;
        son = k * 2 + 1;
        while (son <= stackSize)
        {
            if (stack[k - 1] <= stack[son - 1])
                break;
            int temp = stack[k - 1];
            stack[k - 1] = stack[son - 1];
            stack[son - 1] = temp;
            k *= 2;
            son = k * 2 + 1;
        }
    }

    int top()
    {
        if (stackSize == 0)
            return INT_MIN;
        return stack[0];
    }

    int getMin()
    {
        if (stackSize == 0)
            return INT_MIN;
        return stack[0];
    }
};

int main(){
    MinStack minStack;
    minStack.push(2);
    minStack.push(3);
    minStack.push(1);
    minStack.push(4);
    cout << minStack.top() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    minStack.pop();
    system("pause");
}