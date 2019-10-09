#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
const ll INF = 1e17;

void slove()
{
	int n, k;
	cin >> n >> k;
	vector<int> A(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	sort(A.begin(), A.end());
	int day = 1, eated = 1, res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (A[i] >= day)
		{
			res++;
			day = eated / k + 1;
			eated++;
		}
		else
		{
			continue;
		}
	}
	cout << res << endl;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		slove();
	}
	return 0;
}
