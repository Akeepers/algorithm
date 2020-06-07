#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int max_l = pow(10, 9);
string get_program(string a) {
    int last_pos = -1, last_1 = 0;
    vector<pair<int, int>> s;
    vector<string> last = {""};
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '(') {
            cout << i << " " << a[i - 1] - '0' << " " << endl;
            int begin = s.empty() ? last_1 : s.back().first + 1;
            int len = i - begin - 1;
            // string temp = a.substr(begin, i - begin - 1);
            cout << len << ":" << a.substr(begin, len) << endl;
            if (!s.empty()) {
                last.push_back(a.substr(begin, len));
            } else {
                last[last.size() - 1] += a.substr(begin, len);
            }
            s.push_back({i, a[i - 1] - '0'});
        } else if (a[i] == ')') {
            int begin = s.back().first + 1;
            int cnt = s.back().second;

            s.pop_back();
            if (s.empty()) {
                begin = last_pos + 1;
                string cur = a.substr(begin, i - begin);
                string temp = "";
                while (cnt--) {
                    temp += cur;
                }
                cout << "be:" << begin << ", leng:" << i - begin << endl;
                cout << cur << ":" << temp << endl;
                last.push_back(temp);
                cout << last.back() << endl;
            } else {
                string cur = last.back() + a.substr(begin, i - begin);
                cout << "be:" << begin << ", leng:" << i - begin << endl;
                string temp = "";
                while (cnt--) {
                    temp += cur;
                }
                cout << cur << ":" << temp << endl;
                last[last.size() - 1] += temp;

                cout << last.back() << endl;
            }
            last_pos = s.empty() ? -1 : i;
            last_1 = i + 1;
        }
    }
    if (last_1 <= a.size() - 1) {
        last.push_back(a.substr(last_1));
    }
    string res = "";
    for (auto& item : last) {
        res += item;
    }
    return res;
}

unordered_map<char, pair<int, int>> nexts = {
    {'S', {0, 1}}, {'N', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}};

void slove() {
    string str;
    cin >> str;
    if (str.find("(") != string::npos) {
        str = get_program(str);
    }
    cout << str << endl;
    int x = 0, y = 0;
    for (auto& c : str) {
        pair<int, int> next = nexts[c];
        x += next.first;
        y += next.second;
        x = (x + max_l) % max_l;
        y = (y + max_l) % max_l;
    }
    cout << x + 1 << " " << y + 1 << endl;
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
