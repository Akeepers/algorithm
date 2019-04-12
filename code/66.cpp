#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;
        while(pos>=0){
            int digit = digits[pos] + 1;
            if(digit==10){
                digits[pos] = 0;
                pos--;
            }else{
                digits[pos] = digit;
                break;
            }
        }
        if(pos==-1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main()
{
    system("pause");
    return 0;
}