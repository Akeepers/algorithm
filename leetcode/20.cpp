#include <iostream>
#include <map>
#include <stack>

using namespace std;
class Solution
{

  public:
    bool isValid(string s)
    {
        map<char, char> brackets;
        brackets.insert(pair<char, char>('(', ')'));
        brackets.insert(pair<char, char>('[', ']'));
        brackets.insert(pair<char, char>('{', '}'));

        stack<char> st;

        for (auto c:s)
        {          
            if ((c == '(') || (c == '[') || (c == '{'))
                st.push(c);
            else
            {
                if (st.size() == 0)
                    return false;
                else
                {
                    if (c == brackets[st.top()])
                        st.pop();
                    else
                        return false;
                }
            }
        }

        if (st.size() == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    solution.isValid("()");
    system("pause");
    return 0;
}