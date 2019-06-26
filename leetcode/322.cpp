#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
// dp solution
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//dfs solution
class Solution2
{
private:
    void change(vector<int> &coins, int pos, int amount, int &answer, int curCount)
    {
        if (pos == coins.size() - 1)
        {
            if (amount % coins[pos] == 0)
            {
                answer = min(answer, curCount + amount / coins[pos]);
            }
        }
        else
        {
            for (int i = amount / coins[pos]; i >= 0&&count+k<answer; --i)
            {
                change(coins, pos + 1, amount - i * coins[pos], answer, curCount + i);
            }
        }
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.rbegin(), coins.rend());
        int answer = INT_MAX;
        change(coins, 0, amount, answer, 0);
        return answer == INT_MAX ? -1 : answer;
    }
};

int main()
{
    system("pause");
    return 0;
}