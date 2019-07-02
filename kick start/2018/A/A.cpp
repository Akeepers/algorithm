#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long long getPre(long long n)
{
    int len = 0;
    long long num = n;
    vector<int> nums(20, 0);
    while (num != 0)
    {
        nums[len++] = num % 10;
        num /= 10;
    }

    auto digits = nums;
    for (int i = len - 1; i >= 0; --i)
    {
        if (digits[i] % 2 != 0)
        {
            digits[i]--;
            for (int j = i - 1; j >= 0; j--)
            {
                digits[j] = 8;
            }
            break;
        }
    }
    long long ans = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        ans = ans * 10 + digits[i];
    }
    return ans;
}

long long getNext(long long n)
{
    int len = 0;
    long long num = n;
    vector<int> nums(20, 0);
    while (num != 0)
    {
        nums[len++] = num % 10;
        num /= 10;
    }

    auto digits = nums;
    for (int i = len - 1; i >= 0; --i)
    {
        if (digits[i] % 2 != 0)
        {
            if (digits[i] == 9)
            {
                return LONG_LONG_MAX;
            }
            else
            {
                digits[i]++;
                for (int j = i - 1; j >= 0; j--)
                {
                    digits[j] = 0;
                }
            }
            break;
        }
    }
    long long ans = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        ans = ans * 10 + digits[i];
    }
    return ans;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        long long n;
        cin >> n;
        auto ret = min(n - getPre(n), getNext(n) - n);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}