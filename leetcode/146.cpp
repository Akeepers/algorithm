#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class LRUCache
{
private:
    int _capacity;
    int _occupied;
    queue<int> _opOrder;
    unordered_map<int, int> _visit;
    unordered_map<int, int> _cache;

public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
        _occupied = 0;
    }

    int get(int key)
    {
        if (_cache.find(key) == _cache.end())
            return -1;
        _visit[key]++;
        _opOrder.push(key);
        return _cache[key];
    }

    void put(int key, int value)
    {

        if (_cache.find(key) != _cache.end())
        {
            _cache[key] = value;
            _opOrder.push(key);
            _visit[key]++;
        }
        else
        {
            if (_occupied == _capacity)
            {
                auto leastUsed = _opOrder.front();
                unordered_map<int, int>::iterator it;
                while ((it = _visit.find(leastUsed)) != _visit.end())
                {
                    _visit[leastUsed]--;
                    if (_visit[leastUsed] == 0)
                        _visit.erase(it);
                    _opOrder.pop();
                    leastUsed = _opOrder.front();
                }
                auto iter = _cache.find(leastUsed);
                _cache.erase(iter);
                _opOrder.pop();
                _occupied--;
            }
            _cache.insert({key, value});
            _opOrder.push(key);
            _occupied++;
        }
    }
};
int main()
{
    LRUCache cache(2 /* capacity */);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);    // returns 1
    cache.put(3, 3); // evicts key 2
    cache.get(2);    // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    cache.get(1);    // returns -1 (not found)
    cache.get(3);    // returns 3
    cache.get(4);    // returns 4
    system("pause");
    return 0;
}