#include <iostream>
#include <set>
#include <vector>

using namespace std;

pair<int, int> calLocation(int m, int n, pair<int, int> start, const string &instructions)
{
    vector<set<pair<int, int>>> rows(m + 1), cols(n + 1);
    rows[start.first].insert(make_pair(start.first, start.first));
    rows[start.second].insert(make_pair(start.second, start.second));

    int x = start.first, y = start.second;

    for (auto item : instructions)
    {
        if (item == 'E' || item == 'W')
        {
            item == 'E' ? y++ : y--;
            auto it = rows[x].lower_bound(make_pair(y, 0));
            if (it != rows[x].end() && it->second == y)
            {
                auto it2 = next(it, 1);
                if (it2 != rows[x].end() && it2->first == y+1)
                {
                    rows[x].insert(make_pair(it->first, it2->second));
                    rows[x].erase(it);
                    rows[x].erase(it2);
                }
                else
                {
                    rows[x].insert(make_pair(it->first, ++y));
                    rows[x].erase(it);
                }
            }
            else
            {
            }
            if (it == rows[x].end() || it->second < y)
            {
                rows[x].insert(make_pair(y, y));
            }
        }
    }
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, r, c, s_r, s_c;
        string instructions;
        cin >> n >> r >> c >> s_r >> s_c >> instructions;

        auto ret = calLocation(r, c, pair<int, int>(s_r, s_c), instructions);
        cout << "Case #" << i << ": " << ret.first << "  " << ret.second << endl;
    }
    return 0;
}