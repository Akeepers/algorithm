#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	auto t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ":";
		int n, g, m;
		cin >> n >> g>>m;
		vector<vector<int>> consulates(n,vector<int>(2,0));
		vector<int> clockwiseGuest, antiGuest;

		for (int j = 0; j < g; j++)
		{
			int x;
			char c;
			cin>>x>>c;
			if(c=='C'){
				clockwiseGuest.emplace_back(x);
			}else{
				antiGuest.emplace_back(x);
			}
		}
		int pos;
		for(auto item:clockwiseGuest){
			pos=(item+m)%n;
			consulates[pos][0]++;
			consulates[pos][1]=m;
		}
		for(int i=pos-1;i!=pos;i=(i-1+m)%n){
			
		}
		cout << endl;
	}
	return 0;
}
