#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0;
        int index = 0;
        int before = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            sum += gas[i] - cost[i];
            if (sum < 0)
            {
                before += sum;
                sum = 0;
                index = i + 1;
            }
        }
        if (before + sum < 0)
            return -1;
        return index;
    }
};

int main()
{
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    solution.canCompleteCircuit(gas, cost);
    system("pause");
    return 0;
}