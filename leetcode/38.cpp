#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string str = "1";
        while (--n)
        {
            string cur = "";
            int count = 1;
            for (int i = 0; i < str.size() - 1; ++i)
            {
                if (str[i] == str[i + 1])
                    count++;
                else
                {
                    cur += to_string(count) + str[i];
                    count = 1;
                }
            }
            cur += to_string(count) + str.back();
            str = cur;
        }
        return str;
    }
};
int main()
{
    Solution solution;
    solution.countAndSay(4);
    system("pause");
    return 0;
}