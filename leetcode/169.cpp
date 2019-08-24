#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
      unordered_map<int, int> counts;
      int n = nums.size();
      for(auto num:nums){
        if(++counts[num]>n/2){
          return num;
        }
      }
      return 0;
    }
};

int main()
{
    system("pause");
    return 0;
}
