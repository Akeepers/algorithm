#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  private:
    void maxProfitInFrontOrder(vector<int> &prices, vector<int> &dp)
    {
        int min = prices[0];
        dp[0] = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            profit = max(prices[i] - min, profit);
            dp[i] = profit;
            if (min > prices[i])
                min = prices[i];
        }
    }
    void maxProfitInBackOrder(vector<int> &prices, vector<int> &dp)
    {
        int max1 = prices.back();
        dp.back() = 0;
        int profit = 0;
        for (int i = prices.size() - 2; i >= 0; --i)
        {
            profit = max(max1 - prices[i], profit);
            dp[i] = profit;
            if (max1 < prices[i])
                max1 = prices[i];
        }
    }

  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        vector<int> frontDp(prices.size(), 0);
        vector<int> backDp(prices.size(), 0);
        maxProfitInFrontOrder(prices, frontDp);
        maxProfitInBackOrder(prices, backDp);
        int profit = 0;
        for (int i = 1; i < prices.size() - 1; ++i)
        {
            profit = max(frontDp[i] + backDp[i + 1], profit);
        }
        profit = max(frontDp.back(), profit);
        return profit;
    }
};

int main()
{
    vector<int> inputs = {3, 2, 6, 5, 0, 3};
    Solution solution;
    cout << solution.maxProfit(inputs) << endl;
    system("pause");
    return 0;
}