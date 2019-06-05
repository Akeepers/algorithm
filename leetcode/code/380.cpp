#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;
class RandomizedSet
{
  private:
    unordered_map<int, int> map;
    vector<int> vec;
    std::default_random_engine generator;

  public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;
        vec.emplace_back(val);
        map[val] = vec.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;
        int index = map[val];
        map[vec.back()] = index;
        exchange(vec[index], vec[vec.size() - 1]);
        vec.pop_back();
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int n = vec.size();
        int index = generator() % n;
        return vec[index];
    }
};

int main()
{
    system("pause");
    return 0;
}