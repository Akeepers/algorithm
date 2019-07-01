#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int minTime(long long n)
{
    int len = 0;
    vector<int> nums(17,0);
    while (n != 0)
    {
        nums[len++] = n % 10;
        n /= 10;
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
        }
    }
    long long ans = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        ans = ans * 10 + digits[i];
    }

    digits = nums;
    int pre = 0;
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
        }
    }
    long long ans1=0;
    for (int i=16;i>=0;--i){
        ans1=ans1*10+digits[i];
    }
    return min(n-ans1,n-ans);
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