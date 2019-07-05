#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        vector<int> res;
        priority_queue<pair<int, int>> queue;
        int n = nums.size();
        for (int i = 0; i < n;++i){
            while(!queue.empty()&&queue.top().second<=i-k)
                queue.pop();
            queue.push(make_pair(nums[i], i));
            if(i>=k-1){
                res.emplace_back(queue.top().first);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        vector<int> res;
        deque<int> queue;
        int n = nums.size();
        for (int i = 0; i < n;++i){
            while(!queue.empty()&&queue.front()<=i-k)
                queue.pop_front();
            while(!queue.empty()&&nums[queue.back()]<=nums[i])
                queue.pop_back();
            queue.push_back(i);
            if(i>=k-1){
                res.emplace_back(nums[queue.front()]);
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