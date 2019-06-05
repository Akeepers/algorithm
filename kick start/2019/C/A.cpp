#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

pair<int, int> calLocation(int m, int n, pair<int, int> start, const vector<char> &instructions)
{
    unordered_map<int, unordered_set<int>> visit;

    int i = start.first, j = start.second;
    visit[i].insert(j);
    for (auto item : instructions)
    {
        switch (item)
        {
        case 'E':
            do
            {
                j++;
            } while (visit.find(i) != visit.end() && visit[i].find(j) != visit[i].end());
            break;
        case 'W':
            do
            {
                j--;
            } while (visit.find(i) != visit.end() && visit[i].find(j) != visit[i].end());
            break;
        case 'S':
            do
            {
                i++;
            } while (visit.find(i) != visit.end() && visit[i].find(j) != visit[i].end());
            break;
        case 'N':
            do
            {
                i--;
            } while (visit.find(i) != visit.end() && visit[i].find(j) != visit[i].end());
            break;
        }
        visit[i].insert(j);
    }
    return pair<int, int>(i , j );
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n, r, c, s_r, s_c;
        cin >> n >> r >> c >> s_r >> s_c;
        char temp;
        int maxN = 0, maxS = 0, maxW = 0, maxE = 0;
        vector<char> instructions(n);
        int j = 0;
        while (n--)
        {
            cin >> temp >> right;
            instructions[j++] = temp;
        }
        auto ret = calLocation(r, c, pair<int, int>(s_r, s_c), instructions);
        cout << "Case #" << i << ": " << ret.first << "  " << ret.second << endl;
    }
    return 0;
}