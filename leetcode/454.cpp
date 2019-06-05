#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> abSum;
        int res = 0, sum = 0;
        for (auto a : A)
        {
            for (auto b : B)
            {
                sum = a + b;
                if (abSum.find(sum) != abSum.end())
                    abSum[sum]++;
                else
                    abSum.insert({sum, 1});
            }
        }
        for (auto c : C)
        {
            for (auto d : D)
            {
                int key = -c - d;
                if (abSum.find(key) != abSum.end())
                    res += abSum[key];
            }
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}