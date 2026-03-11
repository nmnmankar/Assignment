#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value)
    {

        if (mp.find(key) != mp.end())
        {
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity)
        {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

    void display()
    {
        for (auto it : cache)
        {
            cout << it.first << ":" << it.second << " ";
        }
        cout << endl;
    }
};

int main()
{

    LRUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cache.display();

    cout << "Get 2: " << cache.get(2) << endl;

    cache.put(4, 40);

    cache.display();

    return 0;
}