#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto item : nums)
        {
            if(item<=first){
                first = item;
            }else if(item<=second){
                second = item;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}