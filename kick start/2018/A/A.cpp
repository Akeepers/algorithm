#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int minTime(int n)
{
    if (n == 0)
        return 0;
    int temp = n;
    stack<int> digits;
    while (temp != 0)
    {
        digits.push(temp % 10);
        temp /= 10;
    }
    bool flag = false;
    int newNum = 0;
    while(!digits.empty())
    {
        auto digit = digits.top();
        digits.pop();
        if (digit % 2 != 0){
            flag = true;
        }
        
    }
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n;
        cin >> n;
        auto ret = minTime(n);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}