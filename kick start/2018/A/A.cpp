#include <iostream>
#include <vector>

using namespace std;



long long minTime(long long n)
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

    digits = nums;
    for (int i = len - 1; i >= 0; --i)
    {
        if (digits[i] % 2 != 0)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
                int j = i + 1;
                while (digits[j] == 8)
                    j++;
                digits[j] += 2;
                while ((--j) >= 0)
                    digits[j] = 0;
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
    long long ans1 = digits[len] != 0 ? digits[len] : 0;
    for (int i = len - 1; i >= 0; --i)
    {
        ans1 = ans1 * 10 + digits[i];
    }
    return min(ans1 - n, n - ans);
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n;
        cin >> n;
        auto ret = minTime(n);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}