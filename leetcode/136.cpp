#include <iostream>
#include <vector>
#include <hash_set>

using namespace std;
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(begin(nums), end(nums), 0, std::bit_xor<int>());
    }
};
int main()
{
    system("pause");
    return 0;
}
