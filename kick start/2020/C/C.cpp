#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

double inline __declspec (naked) __fastcall sqrt14(double n){
    _asm fld qword ptr[esp + 4]
    _asm fsqrt
    _asm ret 8
}

bool is_perfect(int n) {
    // if (n < 0) return false;
    if (n == 0) return true;
    int m = (int)sqrt14(n);
    return n == m * m;
}

void slove() {
    int n;
    cin >> n;
    unordered_map<int,int> dict;
    vector<int> nums(n);
    vector<int> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sums[i + 1] = sums[i] + nums[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            auto sum = sums[j] - sums[i - 1];
            if(sum<0) continue;
            int tail = sum % 10;
            if (tail == 0 ||tail == 1 || tail == 4 || tail == 5 || tail == 6 || tail == 9 )
            {
                dict[sum]++;
            }
            // if (dict.count(sum)) res++;
            // else if(is_perfect(sum)) {
            //     res++;
            //     dict.insert(sum);
            // }
        }
    }
    for(auto item:dict){
        if(is_perfect(item.first)){
            res+=item.second;
        }
    }
    cout << res << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        slove();
    }
    return 0;
}
