#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    bool isValid(char first, char second)
    {
        return first == '1' || (first == '2' && second <= '6');
    }

  public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        int cur = 0, f_1 = 1, f_2 = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int temp = f_1;
            if (s[i] == '0')
            {
                if (!isValid(s[i - 1], s[i]))
                    return 0;
                cur = f_2;
            }
            else
            {
                if (isValid(s[i - 1], s[i]))
                    cur = f_1 + f_2;
                else
                    cur = f_1;
            }
            f_1 = cur;
            f_2 = temp;
        }
        return cur;
    }
};

int main()
{
    system("pause");
    return 0;
}
