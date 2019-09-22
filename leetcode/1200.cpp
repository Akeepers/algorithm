#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int min = INT_MAX;
        char res;
        for (auto letter : letters)
        {
            int cur = letter > target ? letter - target : 'z' - target + (letter - 'a') + 1;
            if (cur < min)
            {
                min = cur;
                res = letter;
            }
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}