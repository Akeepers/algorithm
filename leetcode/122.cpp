#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int min = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size() - 1; ++i)
        {
            if (prices[i] < min)
            {
                min = prices[i];
                continue;
            }
            if (prices[i] > prices[i + 1])
            {
                profit += prices[i] - min;
                min = prices[i + 1];
                i++;
            }
        }
        profit += prices.back() - min > 0 ? prices.back() - min : 0;
        return profit;
    }
};

int main()
{
    system("pause");
    return 0;
}