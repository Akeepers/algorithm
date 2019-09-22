#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		int diff = INT_MAX,n=arr.size();
		sort(arr.begin(), arr.end());
		for(int i=0;i<n-1;++i)
		{
			diff = min(diff, arr[i + 1] - arr[i]);
		}
		vector<vector<int>> res;
		for (int i = 0; i < n - 1; ++i)
		{
			if(arr[i + 1] - arr[i]==diff)
			{
				res.emplace_back(vector<int>{arr[i], arr[i + 1]});
			}
		}
		return res;
	}
};


int main()
{
	return 0;
}